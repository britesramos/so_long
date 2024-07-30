/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_checker_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/19 12:41:49 by sramos        #+#    #+#                 */
/*   Updated: 2024/07/29 12:13:06 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Frees the array of the parsed map.
void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

int	ft_num_lines(char **parsed_map)
{
	int	num_lines;

	num_lines = 0;
	while (parsed_map[num_lines])
		num_lines++;
	return (num_lines);
}

void	add_node_and_set_x(int x, int y, t_node *q, char **map)
{
	add_last_node_q(x, y, q);
	map[x][y] = 'X';
}
