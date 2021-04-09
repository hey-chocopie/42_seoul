#ifndef LIBASM_H
# define LIBASM_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

extern size_t ft_strlen(const char *a);
extern char *ft_strcpy(char *dst, const char *src);
extern int ft_strcmp(const char *dst, const char *src);
extern ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
extern ssize_t ft_read(int fildes, void *buf, size_t nbyte);
extern char *ft_strdup(const char *s1);

#endif
