/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:50:50 by apolo-to          #+#    #+#             */
/*   Updated: 2023/08/10 16:07:41 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

/**
 * This ft show the error and call the exit function.
 * @param t_game* Game structure.
 * @param error Error number.
 * @return int (exit)0.
*/
void	ft_show_error(t_game *game, int error)
{
	printf("Error");
	if (error == 1)
		printf(": Algún caracter de la pared exterior del mapa no es válido.\n");
	if (error == 2)
		printf(": Algún caracter del interior del mapa no es válido.\n");
	if (error == 3)
		printf(": El mapa necesita una posición inicial.\n");
	if (error == 4)
		printf(": El mapa necesita una salida.\n");
	if (error == 5)
		printf(": El mapa necesita almenos un objeto coleccionable.\n");
	if (error == 6)
		printf(": No existe un camino valido en el mapa.\n");
	ft_exit(game);
}

/**
 * This ft free the map in game structure
 * @param t_game* Game structure.
 * @return int (exit)0.
*/
void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_rows - 1)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	return ;
}

/**
 * This ft finish the game and free the memory allocated
 * @param t_game* Game structure.
 * @return int (exit)0.
*/
void	ft_exit(t_game *game)
{
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	ft_free_map(game);
	exit(0);
}
