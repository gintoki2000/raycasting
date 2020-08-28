/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:42:25 by thi-nguy          #+#    #+#             */
/*   Updated: 2020/08/28 11:54:14 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

#define BUFFER_SIZE 100

typedef struct		s_arr
{
	int				fd;
	char			*rest;
	struct s_arr	*next;
}					t_arr;

char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strlen(char const *s);
char				*ft_strnew(size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
t_arr				*ft_newlist(const int fd);
char				*ft_checkrest(char **p_n, char *rest);
int					ft_getline(const int fd, char **line, char *rest);
int					get_next_line(int fd, char **line);

#endif