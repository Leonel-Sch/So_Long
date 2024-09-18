/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:34:44 by leonel            #+#    #+#             */
/*   Updated: 2024/09/18 17:51:47 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr_int(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		return (i);
	return (-1);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	join = (char *)malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[i] && s1 != NULL)
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	free((char *)s1);
	return (join);
}

char	*ft_strndup(const char *s, int nb, int i)
{
	char	*dup;

	dup = (char *)malloc(sizeof(char) * ft_strlen_gnl(s) + 1);
	if (!dup)
		return (NULL);
	if (nb > 0)
	{
		while (s[i] && i < nb)
		{
			dup[i] = s[i];
			i++;
		}
		dup[i] = '\0';
		return (dup);
	}
	else
	{
		while (s[i])
		{
			dup[i] = s[i];
			i++;
		}
		dup[i] = '\0';
	}
	return (dup);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
