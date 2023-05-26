#include "header.h"

/**
 * prompt_user - A prompt
 * Return: 0
 */

int prompt_user(void)
{
	char *pmpt = "$ ";
	ssize_t count = 0;

	/**
	 * isatty checks whether fd refers to a terminal
	 */
	if (isatty(STDIN_FILENO) == 1)
	{
		count = write(STDOUT_FILENO, pmpt, 2);
		if  (count == -1)
		{
			exit(0);
		}

	}
	return (0);
}

/**
 * _puts - Print string
 * @str: String value
 * Return: void
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}

/**
 * _getenv - Get path from environ
 * @pname: Pointer to string
 * Return: Pointer to path string, NULL otherwise
 */

char *_getenv(const char *pname)
{
	int a, results;

	for (a = 0; environ[a]; a++)
	{
		results = _strcp(pname, environ[a]);
		if (results == 0)
		{
			return (environ[a]);
		}
	}
	return (NULL);
}

/**
 * mem - Fills mem with constant byte
 * @s: Pointer to char array
 * @b: COnstant byte
 * @n: Number of bytes
 * Return:: Pointer to char array
 */

char *mem(char b, char *s, unsigned int n)
{
	unsigned int i = 0;

	for (; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

/**
 * _env - Prints environ
 *
 * Return: 0
 */

int _env(void)
{
	int a;

	for (a = 0; environ[a]; a++)
	{
		_puts(environ[a]);
	}
	return (0);
}
