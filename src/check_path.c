/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:18:16 by apolo-to          #+#    #+#             */
/*   Updated: 2023/08/13 08:59:31 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * This ft checks all map position recounting elements to find a valid path.
 * This ft is a recursive function.
 * @param t_game* The game structure;
 * @param int row - Initially the player row
 * @param int col - Initially the player column
 * @return void
*/
static void	ft_check_path(t_game *game, int row, int col)
{
	if (game->map[row][col] == 'E')
		game->path_exit_count++;
	if (game->map[row][col] == 'C')
		game->path_collectable_count++;
	if (row < 0 || row > game->map_rows
		|| col < 0 || col > game->map_cols
		|| game->map[row][col] == '1'
		|| game->map[row][col] == 'E'
	)
		return ;
	game->map[row][col] = '1';
	ft_check_path(game, row, (col - 1));
	ft_check_path(game, row, (col + 1));
	ft_check_path(game, (row - 1), col);
	ft_check_path(game, (row + 1), col);
	return ;
}

/**
 * This ft checks if exists a valid path in the map calling a recursive ft.
 * @param t_game* The game structure;
 * @return void
*/
void	ft_check_valid_path(t_game *game)
{
	ft_check_path(game, game->player_row, game->player_col);
	if (game->collectable_count
		== game->path_collectable_count && game->path_exit_count)
		return ;
	else
		ft_show_error(game, 6);
}
