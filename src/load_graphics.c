/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:43:08 by apolo-to          #+#    #+#             */
/*   Updated: 2023/08/15 12:01:31 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

/**
 * This ft load the xpm files to game structure using mlx library
 * @param t_game* game	- Game structure
 * @return void
*/
static void	ft_load_xpm_to_game(t_game *game)
{
	int	width;
	int	height;

	game->wall_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"data/imgs/wall.xpm", &width, &height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"data/imgs/floor.xpm", &width, &height);
	game->collectable_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"data/imgs/point.xpm", &width, &height);
	game->player_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"data/imgs/player.xpm", &width, &height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"data/imgs/exit.xpm", &width, &height);
}

/**
 * This ft print the images in the windows depends on the map letter.
 * @param int row		- Row map position
 * @param int col		- Col map position
 * @param t_game* game	- Game structure
 * @return void
*/
static void	ft_choose_graphic_to_print(int row, int col, t_game *game)
{
	if (game->map[row][col] == '1')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->wall_img, col * 50, row * 50);
	if (game->map[row][col] == '0')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->floor_img, col * 50, row * 50);
	if (game->map[row][col] == 'P')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->player_img, col * 50, row * 50);
	if (game->map[row][col] == 'C')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->collectable_img, col * 50, row * 50);
	if (game->map[row][col] == 'E')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->exit_img, col * 50, row * 50);
}

/**
 * This ft runs over the entire map and calls another ft to print the pieces.
 * @param t_game* game	- Game structure
 * @return void
*/
static void	ft_print_graphics_on_map(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map_rows)
	{
		col = 0;
		while (col < game->map_cols)
		{
			ft_choose_graphic_to_print(row, col, game);
			col++;
		}
		row++;
	}
}

/**
 * This ft execute all fts to print the map.
 * @param t_game* game	- Game structure
 * @return void
*/
void	ft_print_graphics_in_window(t_game *game)
{
	ft_load_xpm_to_game(game);
	ft_print_graphics_on_map(game);
}
