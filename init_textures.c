/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/15 12:07:13 by sramos        #+#    #+#                 */
/*   Updated: 2024/07/29 17:37:47 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_textures(t_game *game, mlx_texture_t*texture)
{
	texture = mlx_load_png("./Textures/0.png");
	game->textures.background = mlx_texture_to_image(game->mlx, texture);
	if (!(game->textures.background))
		return ;
	mlx_delete_texture(texture);
	texture = mlx_load_png("./Textures/P.png");
	game->textures.player = mlx_texture_to_image(game->mlx, texture);
	if (!(game->textures.background))
		return ;
	mlx_delete_texture(texture);
	texture = mlx_load_png("./Textures/C.png");
	game->textures.c = mlx_texture_to_image(game->mlx, texture);
	if (!(game->textures.background))
		return ;
	mlx_delete_texture(texture);
	texture = mlx_load_png("./Textures/E.png");
	game->textures.exit = mlx_texture_to_image(game->mlx, texture);
	if (!(game->textures.background))
		return ;
	mlx_delete_texture(texture);
	texture = mlx_load_png("./Textures/1.png");
	game->textures.wall = mlx_texture_to_image(game->mlx, texture);
	if (!(game->textures.background))
		return ;
	mlx_delete_texture(texture);
}
