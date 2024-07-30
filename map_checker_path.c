/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_checker_path.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/27 14:24:42 by sramos        #+#    #+#                 */
/*   Updated: 2024/07/29 11:54:16 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_node	*find_player(t_game *map)
{
	int		x;
	int		y;
	t_node	*q;

	x = 0;
	y = 0;
	q = NULL;
	while (map->map[y][x] != '\0')
	{
		while (map->map[y][x] != '\0')
		{
			if (map->map[y][x] == 'P')
			{
				q = create_node(y, x, q);
				map->map[y][x] = 'X';
				map->player_position_x = x;
				map->player_position_y = y;
				return (q);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	add_last_node_q(int x, int y, t_node *q)
{
	t_node	*new;

	new = q;
	while (new->next != NULL)
		new = new->next;
	if (new->next == NULL)
		new->next = create_node(x, y, q);
}

t_node	*remove_first_node_q(t_node *q)
{
	t_node	*first;

	first = q;
	q = q->next;
	free(first);
	first = NULL;
	return (q);
}

int	check_xs(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_valid_path(t_game *map)
{
	t_node	*q;

	q = find_player(map);
	while (q != NULL)
	{
		if (map->map[q->x - 1][q->y] == 'C' || map->map[q->x - 1][q->y] == 'E'
			|| map->map[q->x - 1][q->y] == '0')
			add_node_and_set_x(q->x - 1, q->y, q, map->map);
		if (map->map[q->x + 1][q->y] == 'C' || map->map[q->x + 1][q->y] == 'E'
			|| map->map[q->x + 1][q->y] == '0')
			add_node_and_set_x(q->x + 1, q->y, q, map->map);
		if (map->map[q->x][q->y - 1] == 'C' || map->map[q->x][q->y - 1] == 'E'
			|| map->map[q->x][q->y - 1] == '0')
			add_node_and_set_x(q->x, q->y - 1, q, map->map);
		if (map->map[q->x][q->y + 1] == 'C' || map->map[q->x][q->y + 1] == 'E'
			|| map->map[q->x][q->y + 1] == '0')
			add_node_and_set_x(q->x, q->y + 1, q, map->map);
		q = remove_first_node_q(q);
	}
	if (check_xs(map->map) == 1)
		return (1);
	return (0);
}
