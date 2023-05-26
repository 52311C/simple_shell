#include "header.h"

/**
 * _fork - Creates child process
 * @arv: Pointer to array of string users
 * @buff: Pointer to string
 * @pathbuffer: Pointer to input
 * Return: 0
 */

int _fork(char *buff, char **arv, char *pathbuffer)
{
	int i = 0, EXIT_STATUS = 0, flag, results;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		results = execve(pathbuffer, arv, environ);
		if (results == -1)
		{
			perror(arv[0]);
			for (; arv[i]; i++)
			{
				free(av[i]);
			}
			free(arv);
			free(buff);
			exit(127);
		}
	}
	wait(&flag);
	/**
	 * WIFEXITED is a query status to see if a child
	 * process ended normally
	 */
	if (WIFEXITED(flag))
	{
		EXIT_STATUS = WEXITSTATUS(flag);
	}
	for (; av[i]; i++)
	{
		free(av[i]);
	}
	free(buff);
	free(arv);
	return (EXIT_STATUS);
}

/**
 * builtin - Checks for builtins
 * @arv: Pointer to array of string user
 * @buff: Pointer to string
 * @EXIT_STATUS: Exit status of execve
 * Return: 1 if string == env, 0 otherwise
 */

int builtin(char *buff, char **arv, int EXIT_STATUS)
{
	int i = 0;

	if (_strcp(arv[0], "env") == 0)
	{
		_env();
		for (; arv[i]; i++)
		{
			free(arv[i]);
		}
		free(buff);
		free(arv);
		return (1);
	}
	else if (_strcp(arv[0], "exit") == 0)
	{
		for (; arv[i]; i++)
		{
			free(arv[i]);
		}
		free(arv);
		free(buff);
		exit(EXIT_STATUS);
	}
	else
	{
		return (0);
	}
}

/**
 * reader - Reads STDIN
 *
 * Return: Pointer to buffer
 */

char *reader(void)
{
	ssize_t count = 0, r;
	char *buff = NULL;
	int i;

	i = 0;
	r = 0;
	count = getline(&buff, &r, STDIN);
	if (count == -1)
	{
		free(buff);
		if (isatty(STDIN_FILENO) != 0)
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		exit(0);
	}
	if (buff[count - 1] == '\n' || buff[count - 1] == '\t')
	{
		buff[count - 1] = '\0';
	}
	for (i = 0; buff[i]; i++)
	{
		if (buff[i] == '#' && buff[i - 1] == ' ')
		{
			buff[i] = '\0'
				break;
		}
	}
	return (buff);
}

/**
 * _pathbuffer - Finds string to call execve on it
 * @arv: Pointer to array of strings
 * @path: Pointer to path string
 * @dup: Pointer to copy of path string
 * Return: Pointer to string to call execve
 */

char *_pathbuffer(char **arv, char *path, char *dup)
{
	char *tkn = NULL, *pathbuffer = NULL, *concat_str = NULL;
	int count = 0, pathflag = 0, i = 0, len_oftkn = 0;
	struct stat t;
	static char tmp[512];

	dup = NULL;
	dup = _strcop(path);
	count = cutup(dup);
	tkn = strtok(dup, ": =");
	while (tkn != NULL)
	{
		concat_str = cat(tmp, arv, tkn);
		if (stat(concat_str, &t) == 0)
		{
			pathbuffer = concat _str;
			pathflag = 1;
			break;
		}
		if (i < count - 2)
		{
			len_oftkn = len_ofstr(tkn);
			if (tkn[len_oftkn + 1] == ':')
			{
				if (stat(arv[0], &t) == 0)
				{pathbuffer = arv[0];
					pathflag = 1;
					break;
				}
			}
		}
		i++;
		tkn = strtok(NULL, ":");
	}
	if (pathflag == 0)
	{
		pathbuffer = av[0];
	}
	free(dup);
	return (pathbuffer);
}

/**
 * main - Code entry for Shell
 *
 * Return: 0
 */

int main(void)
{
	char *buff =  NULL, **arv = NULL, *path = NULL, *pathbuffer NULL,
	     *dup = NULL;
	int EXIT_STATUS = 0;

	signal(SIGINT, SIG_IGN);
	path = _getenv("path");
	if (path == NULL)
	{
		return (-1);
	}
	while (1)
	{
		arv = NULL;
		prompt_user();
		buff = _read();
		if (*buff != '\0')
		{
			arv = token(buff);
			if (arv == NULL)
			{
				free(buff);
				continue;
			}
			pathbuffer = _pathbuffer(arv, path, dup);
			if (builtin(arv, buff, EXIT_STATUS) != 0)
			{
				continue;
			}
			EXIT_STATUS = _fork(arv, buff, pathbuffer);
		}
		else
		{
			free(buff);
		}
	}
	return (0);
}
