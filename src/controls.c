/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:09:56 by apolo-to          #+#    #+#             */
/*   Updated: 2023/08/15 13:26:36 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

/**
 * This ft check the type of movement according to the map character
 * @param int row 		- row positon on map
 * @param int col 		- col positon on map
 * @param t_game* game	- Game structure
 * @return int			- 1(ok), 0(error)
*/
static int	ft_check_movement(int row, int col, t_game *game)
{
	if (game->map[row][col] == 'E')
	{
		if (game->collectable_count != 0)
			return (0);
		game->movements++;
		printf ("🎉 Has ganado en %i movimientos 🎉\n", game->movements);
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
	printf("Nº movimientos: %i\n", game->movements);
	return (1);
}

/**
 * This ft execute a move depending of the key pressed
 * @param int key		- Key pressed
 * @param t_game* game	- Game structure
 * @return int			- 1(ok), 0(error)
*/
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

/**
 * This ft execute others fts depending of the key pressed
 * @param int key		- Key pressed
 * @param t_game* game	- Game structure
 * @return int			- 1(ok)
*/
int	ft_controls(int key, t_game *game)
{
	int		works;
	char	*str;

	str = "Movimientos:";
	works = 0;
	if (key == 53 || key == 12)
		ft_exit(game);
	if (key == 13 || key == 126 || key == 1 || key == 125
		|| key == 0 || key == 123 || key == 2 || key == 124)
		works = ft_move(key, game);
	if (works)
		ft_print_graphics_in_window(game);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 20, 0x4d4282, str);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 98, 20,
		0x4d4282, ft_itoa(game->movements));
	return (1);
}
