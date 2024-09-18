/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:34:52 by leonel            #+#    #+#             */
/*   Updated: 2024/09/18 17:51:10 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*get_next_line(int fd);
int		ft_strchr_int(const char *s, int c);
char	*ft_strndup(const char *s, int nb, int i);
char	*ft_strcpy(char *dest, char *src);
void	ft_error(char *buffer, char *temp);
void	ft_dependance(char *temp, char **line, char *buf, int reed);
void	ft_position(char **line, int pos, char *temp);

#endif