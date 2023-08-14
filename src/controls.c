/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:09:56 by apolo-to          #+#    #+#             */
/*   Updated: 2023/08/14 15:21:06 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_movement(int row, int col, t_game *game)
{
	if (game->map[row][col] == 'E')
	{
		if (game->collectable_count != 0)
			return (0);
		printf ("¡Enhorabuena, has ganado!");
		ft_exit(game);
	}
	if (game->map[row][col] == '0')
	{
		game->map[row][col] = 'P';
		game->player_row = row;
		game->player_col = col;
		game->movements++;
	}
	if (game->map[row][col] == 'C')
	{
		game->map[row][col] = 'P';
		game->player_row = row;
		game->player_col = col;
		game->collectable_count--;
		game->movements++;
	}
	return (1);
}

static int	ft_move(int key, t_game *game)
{
	int	row;
	int	col;
	int	move_row;
	int	move_col;
	int	works;

	row = game->player_row;
	col = game->player_col;
	move_row = 0;
	move_col = 0;
	if (key == 13 || key == 126)
		move_row = -1;
	if (key == 1 || key == 125)
		move_row = 1;
	if (key == 0 || key == 123)
		move_col = -1;
	if (key == 2 || key == 124)
		move_col = 1;
	if (game->map[row + move_row][col + move_col] == '1')
		return (0);
	works = ft_check_movement((row + move_row), (col + move_col), game);
	if (works == 0)
		return (0);
	game->map[row][col] = '0';
	return (1);
}

int	ft_controls(int key, t_game *game)
{
	int	works;

	works = 0;
	if (key == 53)
		ft_exit(game);
	if (key == 13 || key == 126 || key == 1 || key == 125
		|| key == 0 || key == 123 || key == 2 || key == 124)
		works = ft_move(key, game);
	if (works)
		ft_print_graphics_in_window(game);
	return (1);
}
