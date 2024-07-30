/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/06 11:43:16 by sramos        #+#    #+#                 */
/*   Updated: 2024/07/29 17:49:23 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_struct(t_game *game)
{
	game->moves = 0;
	game->c_count = 0;
	game->p_count = 0;
	game->e_count = 0;
	game->num_lines = 0;
	game->instances_count = 0;
	game->player_position_x = 0;
	game->player_position_y = 0;
}

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->textures.background);
	mlx_delete_image(game->mlx, game->textures.player);
	mlx_delete_image(game->mlx, game->textures.c);
	mlx_delete_image(game->mlx, game->textures.exit);
	mlx_delete_image(game->mlx, game->textures.wall);
}

int	main(int argc, char **argv)
{
	t_game			game;
	mlx_texture_t	*texture;

	texture = NULL;
	initialize_struct(&game);
	if (argc != 2)
		return (1);
	if (argc == 2)
	{
		if (map_checker(argv[1], &game) == 1)
			return (1);
		game.map = parser(argv[1]);
		game.mlx = mlx_init((ft_strlen(game.map[1]) - 1) * PIXELS,
				(game.num_lines) * PIXELS, "Best game ever!", false);
		if (!(game.mlx))
			return (1);
		init_textures(&game, texture);
		init_game(&game);
		mlx_key_hook(game.mlx, ft_key_actions, &game);
		mlx_loop(game.mlx);
		delete_images(&game);
		mlx_terminate(game.mlx);
		ft_free_map(game.map);
	}
	return (0);
}
