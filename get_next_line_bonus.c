/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:10:02 by sel-bouy          #+#    #+#             */
/*   Updated: 2023/12/11 14:26:14 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_later(char *buff)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buff)
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	if (buff[i] == '\0')
		return (free(buff), NULL);
	line = malloc (sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!line)
		return (free(buff), NULL);
	j = 0;
	while (buff[i])
	{
		line[j++] = buff[i++];
	}
	line[j] = '\0';
	free(buff);
	return (line);
}

char	*ft_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
	{
		return (NULL);
	}
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*buff;
	int		byte;

	buff = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buff)
	{
		free(res);
		return (NULL);
	}
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
			return (free(buff), free(res), NULL);
		buff[byte] = '\0';
		res = ft_strjoin(res, buff);
		if (ft_search(buff, '\n'))
			break ;
	}
	free(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buff[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = read_file(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = ft_line(buff[fd]);
	buff[fd] = ft_later(buff[fd]);
	if (!line)
	{
		free(buff[fd]);
		buff[fd] = NULL;
	}
	return (line);
}
