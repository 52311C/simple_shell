#include "header.h"

/**
 * strcop - Duplicates string
 * @str: String pointer
 * Return: Pointer to string
 */

char *strcop(char *str)
{
	int i;
	char *dest;

	dest = NULL;
	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] ! = '\0'; i++)
	{
	}
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
	{
		return (NULL);
	}
	for ( i= 0; str[i] != '\0'; i++)
	{
		dest[i] = str[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * len_ofstr - Length of string
 * @c: Character type
 * Return: i
 */

int len_ofstr(char *c)
{
	int i = 0;

	for  (i = 0; c[i]; i++)
	{
	}
	return (i);
}

/**
 * str_cat - Concantenation
 * @dest: Destination
 * @src: Source
 * Return: pointer to dest
 */

char *str_cat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	for (j = 0; src[j] != '\0'; j++, i++)
	{
		dest[i] = src[j];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcp - Compare strings
 * @s1: First string
 * @s2: Second string
 * Return: int
 */

int _strcp(const char *s1, const char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	return (*s1 - *s2);
}

/**
 * int cutup -  Counts words in string
 * @str: Pointer to string
 * Return: Number of words
 */

int cutup(char *str)
{
	int i;
	int flag = 1, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && flag == 1)
		{
			count = count + 1;
			flag = 0;
		}
		if (str[i + 1] == ' ')
		{
			flag = 1;
		}
	}
	return (count);
}

/**
 * _putchar - Prints a char
 * @c: Character
 * Return: Return value of write
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * mem - Fills mem with constant byte
 * @s: Pointer to char array
 * @b: Constant byte
 * @n: Number of bytes
 * Return: Pointer to char array
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
 * Return : 0
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

/**
 * _puts - Print string
 * @str: String valu
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
	int a, results

	for (a = 0; environ[a]; a++)
	{
		results = _pthstrcp(pname, environ[i]);
		if (results == 0)
		{
			return (environ[a]);
		}
	}
	return (NULL);
}
