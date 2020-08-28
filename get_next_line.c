/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:32:19 by thi-nguy          #+#    #+#             */
/*   Updated: 2020/01/17 16:24:58 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	i = 0;
	sub_str = (char *)malloc(len + 1);
	if (sub_str == NULL || s == NULL)
		return (NULL);
	while (i < len)
	{
		sub_str[i] = s[start];
		i++;
		start++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

t_arr		*ft_newlist(const int fd)
{
	t_arr	*new;

	if (!(new = (t_arr*)malloc(sizeof(t_arr))))
		return (NULL);
	new->fd = fd;
	new->rest = ft_strnew(BUFFER_SIZE);
	new->next = NULL;
	return (new);
}

char		*ft_checkrest(char **p_n, char *rest)
{
	char	*str;
	char	*tmp;

	if ((*p_n = ft_strchr(rest, '\n')) != NULL)
	{
		tmp = ft_strsub(rest, 0, *p_n - rest);
		ft_strcpy(rest, ++(*p_n));
		return (tmp);
	}
	str = ft_strnew(ft_strlen(rest) + 1);
	tmp = str;
	while (*str)
		str++;
	while (*rest)
	{
		*str = *rest;
		*rest = '\0';
		str++;
		rest++;
	}
	*str = '\0';
	return (tmp);
}

int			ft_getline(const int fd, char **line, char *rest)
{
	char		buf[BUFFER_SIZE + 1];
	char		*p_n;
	char		*ptmp;
	int			byte_read;

	p_n = NULL;
	*line = ft_checkrest(&p_n, rest);
	while (p_n == 0 && ((byte_read = read(fd, buf, BUFFER_SIZE)) != 0))
	{
		buf[byte_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strcpy(rest, ++p_n);
			while (*(--p_n))
			{
				*p_n = '\0';
				p_n++;
			}
		}
		ptmp = *line;
		if (!(*line = ft_strjoin(ptmp, buf)) || byte_read < 0)
			return (-1);
		free((void*)ptmp);
	}
	return ((ft_strlen(*line) || ft_strlen(rest) || byte_read) ? 1 : 0);
}

int			get_next_line(const int fd, char **line)
{
	static t_arr	*plist;
	t_arr			*ptmp;
	int				ret;

	if (fd <= 0 || line == 0)
		return (-1);
	if (!plist)
		plist = ft_newlist(fd);
	ptmp = plist;
	while (ptmp->fd != fd)
	{
		if (ptmp->next == NULL)
			ptmp->next = ft_newlist(fd);
		ptmp = ptmp->next;
	}
	ret = ft_getline(fd, line, ptmp->rest);
	return (ret);
}
