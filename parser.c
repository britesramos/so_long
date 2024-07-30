/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/11 12:07:13 by sramos        #+#    #+#                 */
/*   Updated: 2024/07/26 18:37:51 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_line_count(char *argv)
{
	int		line_count;
	char	buf[1];
	int		fd;

	line_count = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, buf, 1) != 0)
	{
		if (buf[0] == '\n')
			line_count++;
	}
	line_count++;
	return (line_count);
}

char	**parser(char *argv)
{
	char	**parsed_map;
	int		fd;
	int		i;
	int		line_count;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit (1);
	line_count = ft_get_line_count(argv);
	if (line_count <= 2)
		exit(1);
	parsed_map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!parsed_map)
		return (NULL);
	while (i < line_count)
	{
		parsed_map[i] = get_next_line(fd);
		i++;
	}
	parsed_map[i] = NULL;
	return (parsed_map);
}
