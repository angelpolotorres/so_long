/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:50:52 by apolo-to          #+#    #+#             */
/*   Updated: 2023/08/10 16:09:21 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * This ft check if the external walls characters are '1'
 * @param t_game* The game structure;
 * @return void
*/
static void	ft_check_map_borders(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->map_cols - 1)
	{
		if (game->map[0][i] != '1' || game->map[game->map_rows - 1][i] != '1')
			ft_show_error(game, 1);
		i ++;
	}
	i = 0;
	while (i <= game->map_rows - 1)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_cols - 1] != '1')
			ft_show_error(game, 1);
		i++;
	}
}

/**
 * This ft count the 'P', 'E' and 'C' elements. And set the player coordanates.
 * @param t_game* The game structure;
 * @param int Row position.
 * @param int Column position.
 * @return void
*/
static void	ft_count_elements(t_game *game, int row, int col)
{
	if (game->map[row][col] == 'P')
	{
		game->player_count++;
		game->player_row = row;
		game->player_col = col;
	}
	if (game->map[row][col] == 'E')
		game->exit_count++;
	if (game->map[row][col] == 'C')
		game->collectable_count++;
}

/**
 * This ft check if characters map are '1','0','P','E' or 'C'.
 * If the character is 'P','E' or 'C' 
 * increment the variable inside the game structure.
 * @param t_game* The game structure structure;
 * @return void
*/
static void	ft_check_map_chars(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map_rows - 1)
	{
		col = 0;
		while (col < game->map_cols - 1)
		{
			if (game->map[row][col] != '1' && game->map[row][col] != '0' &&
				game->map[row][col] != 'C' && game->map[row][col] != 'E' &&
				game->map[row][col] != 'P'
			)
				ft_show_error(game, 2);
			else
				ft_count_elements(game, row, col);
			col++;
		}
		row++;
	}
}

/**
 * This ft check the recount of 'P', 'E' and 'C' elements.
 * @param t_game* The game structure;
 * @return void
*/
static void	ft_check_elements_recount(t_game *game)
{
	if (game->player_count != 1)
		ft_show_error(game, 3);
	if (game->exit_count != 1)
		ft_show_error(game, 4);
	if (game->collectable_count < 1)
		ft_show_error(game, 5);
}

/**
 * This ft execute all neccesary map checkers .
 * @param t_game* The game structure;
 * @param char** Pointer to arguments value recibed from console.
 * @return void
*/
int	ft_check_map_errors(t_game *game, char **argv)
{
	ft_check_map_borders(game);
	ft_check_map_chars(game);
	ft_check_elements_recount(game);
	ft_check_valid_path(game);
	ft_read_map(game, argv);
	printf("todo ok - (quitar)\n");
	return (1);
}
