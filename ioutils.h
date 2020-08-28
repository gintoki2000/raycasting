#ifndef IOUTILS_H
#define IOUTILS_H

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(const char *str);

int		ft_check_arg(char *argv, char *name);
int		ft_check_format(char *argv, char *format);

int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, int n);

#endif
