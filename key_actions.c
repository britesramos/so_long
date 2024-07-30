/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_actions.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/18 15:14:57 by sramos        #+#    #+#                 */
/*   Updated: 2024/07/26 18:34:52 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_game *game)
{
	if (game->map[game->player_position_y][game->player_position_x + 1] != '1')
	{
		game->textures.player->instances->x += PIXELS;
		game->player_position_x++;
		game->moves++;
		printf("%i\n", game->moves);
		c_cleaner(game, game->player_position_x, game->player_position_y);
	}
	home_end_game(game, game->player_position_x, game->player_position_y);
}

void	move_left(t_game *game)
{
	if (game->map[game->player_position_y][game->player_position_x - 1] != '1')
	{
		game->textures.player->instances->x -= PIXELS;
		game->player_position_x--;
		game->moves++;
		printf("%i\n", game->moves);
		c_cleaner(game, game->player_position_x, game->player_position_y);
	}
	home_end_game(game, game->player_position_x, game->player_position_y);
}

void	move_down(t_game *game)
{
	if (game->map[game->player_position_y + 1][game->player_position_x] != '1')
	{
		game->textures.player->instances->y += PIXELS;
		game->player_position_y++;
		game->moves++;
		printf("%i\n", game->moves);
		c_cleaner(game, game->player_position_x, game->player_position_y);
	}
	home_end_game(game, game->player_position_x, game->player_position_y);
}

void	move_up(t_game *game)
{
	if (game->map[game->player_position_y - 1][game->player_position_x] != '1')
	{
		game->textures.player->instances->y -= PIXELS;
		game->player_position_y--;
		game->moves++;
		printf("%i\n", game->moves);
		c_cleaner(game, game->player_position_x, game->player_position_y);
	}
	home_end_game(game, game->player_position_x, game->player_position_y);
}

void	ft_key_actions(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_putendl_fd("	Goodbye 👋", 1);
		mlx_close_window(game->mlx);
	}
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS))
		move_up(game);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS))
		move_down(game);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS))
		move_left(game);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS))
		move_right(game);
}
