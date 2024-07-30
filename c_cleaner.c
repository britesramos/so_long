/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   c_cleaner.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/26 18:33:35 by sramos        #+#    #+#                 */
/*   Updated: 2024/07/29 14:18:56 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	c_cleaner(t_game *game, int y, int x)
{
	int	star_c;

	star_c = 0;
	if (game->map[x][y] == 'C')
	{
		while (star_c <= game->instances_count)
		{
			if (((game->textures.c->instances[star_c].x) / PIXELS) == y
				&& ((game->textures.c->instances[star_c].y) / PIXELS) == x)
			{
				game->textures.c->instances[star_c].enabled = false;
				game->c_count--;
				game->map[x][y] = '0';
				break ;
			}
			star_c++;
		}
	}
}
