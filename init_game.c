/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/16 17:44:11 by sramos        #+#    #+#                 */
/*   Updated: 2024/07/29 17:47:00 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_background(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->num_lines)
	{
		while (game->map[i][j] != '\0' && game->map[i][j] != '\n')
		{
			if (mlx_image_to_window(game->mlx, game->textures.background,
					j * PIXELS, i * PIXELS) < 0)
				break ;
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_map(t_game *game, int i, int j)
{
	while (i < game->num_lines)
	{
		while (game->map[i][j] != '\0' && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->textures.wall,
					j * PIXELS, i * PIXELS);
			if (game->map[i][j] == 'P')
				mlx_image_to_window(game->mlx, game->textures.player,
					j * PIXELS, i * PIXELS);
			if (game->map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->textures.c,
					j * PIXELS, i * PIXELS);
			if (game->map[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->textures.exit,
					j * PIXELS, i * PIXELS);
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	init_background(game);
	init_map(game, i, j);
}
