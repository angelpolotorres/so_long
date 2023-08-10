/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:43:08 by apolo-to          #+#    #+#             */
/*   Updated: 2023/08/10 16:08:42 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

// ft_load_xpm_to_game
// ft_print_graphs_in_map

/**
 * This ft load the xpm files to game structure using mlx library
 * @param t_game* Game structure
 * @return void
*/
static void	ft_load_xpm_to_game(t_game *game)
{
	int	width;
	int	height;

	game->wall_img = mlx_xpm_file_to_image(game->mlx_ptr, "imgs/wall.xpm", &width, &height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx_ptr, "imgs/floor.xpm", &width, &height);
	game->collectable_img = mlx_xpm_file_to_image(game->mlx_ptr, "imgs/point.xpm", &width, &height);
	game->player_img = mlx_xpm_file_to_image(game->mlx_ptr, "imgs/player.xpm", &width, &height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx_ptr, "imgs/exit.xpm", &width, &height);
}

static void	ft_print_map_with_graphics(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map_rows)
	{
		col = 0;
		while (col < game->map_cols)
		{
			if (game->map[row][col] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_img, col * 50, row * 50);
			if (game->map[row][col] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor_img, col * 50, row * 50);
			if (game->map[row][col] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player_img, col * 50, row * 50);
			if (game->map[row][col] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->collectable_img, col * 50, row * 50);
			if (game->map[row][col] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit_img, col * 50, row * 50);
			col++;
		}
		row++;
	}
}

void	ft_print_graphics_in_window(t_game *game)
{
	ft_load_xpm_to_game(game);
	ft_print_map_with_graphics(game);
}
