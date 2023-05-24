#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>

#define buff_size 1024;
int _putchar(char c);
int prompt_user(void);
int _for(char *buff, char**arv, char *pathbuffer);
extern char **environ;
int  builtin(chcar *buff, char**arv, int EXIT_STATUS);
int _strcp(const char *s1, const char *s2);
int cutup(char *str);
int len_ofstr(char *c);
char *str_cat(char *dest, char *src);
char *strcop(char *str);
int _env(void);
char *reader(void);
char token(char *buff);
char *pathbuffer(char **arv, char *path, char *dup);
char *cat(char *tkn, char **arv, char tmp);
int split_pth(char *str);
int cmp_pth(const char *s2, const char *s1);
void _puts(char *str);
char *_getenv(const char *pname);
char *mem(char b, char *s, unsigned int n);
#endif
