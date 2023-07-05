/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:37:01 by lboulang          #+#    #+#             */
/*   Updated: 2022/12/12 23:23:07 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen(const char *s);
char	*ft_join_free(char *str1, char *str2);
char	*ft_strchr(char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_get_line(char *buffer);
char	*ft_get_file(char *buffer, int fd);
char	*ft_update_buffer(char *buffer);
char	*get_next_line(int fd);
#endif