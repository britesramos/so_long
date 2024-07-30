/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_checker_path_utils.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/02 14:40:47 by sramos        #+#    #+#                 */
/*   Updated: 2024/07/29 17:39:50 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Check if the line only has ones.
int	check_firstlast_lines(char *parsed_map, int j)
{
	int	i;

	i = 0;
	while (parsed_map[i + j])
	{
		if (parsed_map[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

//Check if the line dont have ode characters.
int	check_middle_lines(char *line, t_game *map)
{
	int	j;

	j = 1;
	if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
		return (1);
	while (line[j] != '\0')
	{
		if (line[j] != '1' && line[j] != '0' && line[j] != 'E'
			&& line[j] != 'P' && line[j] != 'C' && line[j] != '\n')
			return (1);
		if (line[j] == 'E')
			map->e_count++;
		if (line[j] == 'P')
			map->p_count++;
		if (line[j] == 'C')
		{
			map->c_count++;
			map->instances_count++;
		}
		j++;
	}
	return (0);
}

t_node	*create_node(int x, int y, t_node *q)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		while (q != NULL)
		{
			free(q);
			q = q->next;
		}
		write (1, "Memory allocation failed!\n", 26);
		exit (1);
	}
	node->x = x;
	node->y = y;
	node->next = NULL;
	return (node);
}
