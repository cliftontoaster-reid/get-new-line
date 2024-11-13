/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:52:56 by lfiorell          #+#    #+#             */
/*   Updated: 2024/11/12 17:25:09 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	read_buffer(int fd, char *buffer, int *bytes_read)
{
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[*bytes_read] = '\0';
}

static char	*handle_newline(char *line, char *buffer, char *newline_pos)
{
	line = ft_strnjoin(line, buffer, (newline_pos - buffer) + 1);
	ft_memcpy(buffer, newline_pos + 1, ft_strlen(newline_pos + 1) + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;
	char		*newline_pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (!*buffer)
		{
			read_buffer(fd, buffer, &bytes_read);
			if (bytes_read == 0)
				return (line);
			if (bytes_read < 0)
				return (NULL);
		}
		newline_pos = ft_strchr(buffer, '\n');
		if (newline_pos)
			return (handle_newline(line, buffer, newline_pos));
		line = ft_strnjoin(line, buffer, ft_strlen(buffer));
		buffer[0] = '\0';
	}
}
