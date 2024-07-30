/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sramos <sramos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 11:50:54 by sramos        #+#    #+#                 */
/*   Updated: 2024/07/29 17:39:54 by sramos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <error.h>

# define PIXELS 64

typedef struct textures
{
	mlx_image_t	*background;
	mlx_image_t	*player;
	mlx_image_t	*c;
	mlx_image_t	*exit;
	mlx_image_t	*wall;
}	t_textures;

typedef struct game
{
	mlx_t		*mlx;
	int			num_lines;
	char		**map;
	int			player_position_x;
	int			player_position_y;
	int			moves;
	int			instances_count;
	int			c_count;
	int			p_count;
	int			e_count;
	t_textures	textures;
}	t_game;

typedef struct node
{
	int			x;
	int			y;
	struct node	*next;
}	t_node;

void	ft_initialize_map(t_game *map);

char	**parser(char *argv);

//Map handling.
int		map_checker(char *argv, t_game *map);
int		check_extension(char *argv, char *str);
int		ft_get_line_count(char *argv);
int		check_rectangular(char **parsed_map);
int		ft_strlen_rec(char *parsed_map);
int		check_middle_lines(char *line, t_game *map);
int		check_firstlast_lines(char *parsed_map, int j);
void	ft_free_map(char **map);
t_node	*create_node(int x, int y, t_node *q);
void	add_node_and_set_x(int x, int y, t_node *q, char **map);
void	add_last_node_q(int x, int y, t_node *q);
int		ft_num_lines(char **parsed_map);
int		check_valid_path(t_game *map);
t_node	*find_player(t_game *map);

void	init_textures(t_game *game, mlx_texture_t*texture);
void	init_game(t_game *game);
void	ft_key_actions(mlx_key_data_t keydata, void *mlx);
void	c_cleaner(t_game *game, int y, int x);
void	home_end_game(t_game *game, int y, int x);

#endif