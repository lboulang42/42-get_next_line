/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:36:14 by lboulang          #+#    #+#             */
/*   Updated: 2022/12/12 23:07:57 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_file(char *buffer, int fd)
{
	char	*temp_buffer;
	int		bytes_readed;

	bytes_readed = 1;
	temp_buffer = malloc(BUFFER_SIZE +1 * sizeof(char));
	if (!temp_buffer)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	while (bytes_readed > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_readed = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_readed == -1)
			return (free(buffer), free(temp_buffer), NULL);
		temp_buffer[bytes_readed] = '\0';
		buffer = ft_join_free(buffer, temp_buffer);
	}
	return (free(temp_buffer), buffer);
}

char	*ft_get_line(char *buffer)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	new_line = ft_calloc(i + 2, sizeof(char));
	if (!new_line)
		return (NULL);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		new_line[i] = buffer[i];
	if (buffer[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_update_buffer(char *buffer)
{
	char	*updated_buffer;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	i++;
	updated_buffer = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!updated_buffer)
		return (NULL);
	while (buffer[++j + i])
		updated_buffer[j] = buffer[i + j];
	updated_buffer[j] = '\0';
	return (free(buffer), updated_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = ft_get_file(buffer, fd);
	if (!buffer)
		return (free(buffer), NULL);
	line = ft_get_line(buffer);
	buffer = ft_update_buffer(buffer);
	return (line);
}
