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
	for (i = 0; str[i] != '\0'; i++)
	{
	}
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
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
 * cutup -  Counts words in string
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
