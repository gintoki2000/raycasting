/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:35:44 by thi-nguy          #+#    #+#             */
/*   Updated: 2020/09/18 11:05:24 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char        *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char    *sub_str;
    size_t    i;

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
