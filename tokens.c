#include "header.h"

/**
 * cat - Concantenation
 * @tmp: Static array
 * @arv: Pointer to aguments
 * @tkn: Pointer to token
 * Return: 0
 */

char *cat(char *tkn, char **arv, char *tmp)
{
	int i = 0;
	int n;

	n = atoi(tmp);
	mem(tmp, 0, 512);
	i = len_ofstr(tkn) + len_ofstr(arv[0]) + 2;
	str_cat(tmp, tkn);
	str_cat(tmp, "/");
	str_cat(tmp, arv[0]);
	tmp[i - 1] = '\0';
	return (tmp);
}

/**
 * token - Creates array of tokens
 * @buff: Pointer to user strings
 * Return: Pointer to array
 */

char **token(char *buff)
{
	char  *tkn = NULL, *delm = "\n", **arv = NULL;
	int i, count = 0;

	count = cutup(buff);
	if (!count)
	{
		return (NULL);
	}
	arv = malloc((count + 1) * sizeof(char *));
	if (arv == NULL)
	{
		exit(1);
	}
	tkn = strtok(buff, delm);
	while (tkn != NULL)
	{
		arv[i] = strcop(tkn);
		tkn = strtok(NULL, delm);
		i++;
	}
	arv[i] = NULL;
	return (arv);
}

/**
 * split_pth - Counts path members
 * @str: Pointer to string being counted
 * Return: Number of path member
 */

int split_pth(char *str)
{
	int i, flag = 1, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ':' && flag == 1)
		{
			count = count + 1;
			flag = 0;
		}
		if (str[i + 1] == ':')
		{
			flag = 1;
		}
	}
	return (count);
}

/**
 * cmp_pth - Compare path with environ
 * @s1: *pointer to first value
 * @s2: Pointer to second value
 * Return: 0
 */

int cmp_pth(const char *s2, const char *s1)
{
	int a;

	for (a = 0; s2[a] != '='; a++)
	{
		if (s1[a] != s2[a])
		{
			return (-1);
		}
	}
	return (0);
}
