/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_checker.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/10 11:54:31 by sramos        #+#    #+#                 */
/*   Updated: 2024/07/29 17:47:45 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Check for valid extension ".ber".
int	check_extension(char *argv, char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = ft_strrchr(argv, '.');
	if (!ptr)
		return (1);
	else
	{
		while (ptr[i] != '\0')
		{
			if (ptr[i] != str[i])
				return (1);
			i++;
		}
	}
	return (0);
}

//Check if all lines in the map have the same amout of characters.
int	check_rectangular(char **parsed_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (parsed_map[i])
		i++;
	while (j < i - 1)
	{
		if (ft_strlen(parsed_map[0]) != ft_strlen(parsed_map[j]))
			return (1);
		j++;
	}
	if (ft_strlen(parsed_map[0]) != ft_strlen(parsed_map[j]) + 1)
		return (1);
	return (0);
}

//Check if the map has odd characters.
int	check_char(t_game *map)
{
	int	i;

	i = 0;
	map->num_lines = ft_num_lines(map->map);
	while (i < map->num_lines)
	{
		if (i == 0 && check_firstlast_lines(map->map[i], 1) == 1)
			return (1);
		if (i == map->num_lines && check_firstlast_lines(map->map[i], 0) == 1)
			return (1);
		else if (i != 0 && i != map->num_lines
			&& check_middle_lines(map->map[i], map) == 1)
			return (1);
		i++;
	}
	if (map->e_count != 1 || map->p_count != 1 || map->c_count < 1)
		return (1);
	return (0);
}

static void	error_free(char *str, char **map)
{
	ft_printf("%s", str);
	ft_free_map(map);
}

//Check if the map is a valid map.
int	map_checker(char *argv, t_game *map)
{
	map->map = parser(argv);
	if (check_extension(argv, ".ber") == 1)
	{
		error_free("Incorrect file extension.\n", map->map);
		return (1);
	}
	if (check_rectangular(map->map) == 1)
	{
		error_free("Invalid map!\n", map->map);
		return (1);
	}
	if (check_char(map) == 1)
	{
		error_free("Invalid character!\n", map->map);
		return (1);
	}
	if (check_valid_path(map) == 1)
	{
		error_free("No valid path!\n", map->map);
		return (1);
	}
	ft_free_map (map->map);
	return (0);
}
