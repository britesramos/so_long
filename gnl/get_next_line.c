/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 16:08:17 by sramos        #+#    #+#                 */
/*   Updated: 2024/06/19 15:07:16 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*ft_extline(char *buffer)
{
	int		linelen;
	char	*line;
	int		i;

	linelen = 0;
	i = 0;
	while (buffer[linelen] != '\n' && buffer[linelen] != '\0')
		linelen++;
	if (buffer[linelen] == '\n')
		linelen++;
	line = malloc(linelen + 1 * sizeof(char));
	if (!line)
		return (NULL);
	linelen = 0;
	while (buffer[linelen] != '\n' && buffer[linelen] != '\0')
		line[linelen++] = buffer[i++];
	if (buffer[linelen] == '\n')
		line[linelen++] = buffer[i++];
	line[linelen] = '\0';
	if (*line == '\0')
		return (ft_free(&line), NULL);
	return (line);
}

char	*ft_leftovers(char *buffer, char *line)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = "";
	temp = ft_strjoin_gnl(temp, buffer);
	ft_free(&buffer);
	i = ft_strlen_gnl(line);
	if (line[i] == '\n')
		i++;
	buffer = malloc(ft_strlen_gnl(temp) - ft_strlen_gnl(line) + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	while (temp[i])
	{
		buffer[j] = temp [i];
		i++;
		j++;
	}
	buffer[j] = '\0';
	ft_free(&temp);
	return (buffer);
}

char	*ft_read(int fd, char *buffer)
{
	int		bytes_read;
	char	*pot;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		pot = malloc(sizeof (char) * BUFFER_SIZE + 1);
		if (!pot)
			return (NULL);
		bytes_read = read(fd, pot, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			ft_free(&pot);
			break ;
		}
		if (bytes_read < 0)
			return (ft_free(&pot), ft_free(&buffer), NULL);
		pot[bytes_read] = '\0';
		temp = ft_strjoin_gnl(buffer, pot);
		ft_free(&buffer);
		buffer = temp;
		ft_free(&pot);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (buffer == NULL)
		exit (1);
	line = ft_extline(buffer);
	buffer = ft_leftovers(buffer, line);
	ft_free(&buffer);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	char	*gnl;

// 	// fd = 8;
// 	fd = open("example.txt", O_RDONLY);
// 	i = 1;
// 	if (fd == -1)
// 		return (1);
// 	while (i <= 30)
// 	{
// 		gnl = get_next_line(fd);
// 		printf("[%i]: %s\n", i, gnl);
// 		if (gnl == 0)
// 			break ;
// 		i++;
// 		free (gnl);
// 	}
// 	close(fd);
// 	return (0);
// }
