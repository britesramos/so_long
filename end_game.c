/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   end_game.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/26 18:31:28 by sramos        #+#    #+#                 */
/*   Updated: 2024/07/26 18:36:25 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	home_end_game(t_game *game, int y, int x)
{
	if (game->map[x][y] == 'E' && game->c_count == 0)
	{
		mlx_close_window(game->mlx);
	}
}
