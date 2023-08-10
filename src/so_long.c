/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:40:53 by apolo-to          #+#    #+#             */
/*   Updated: 2023/08/10 16:59:55 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"


int	main(int argc, char **argv)
{
	t_game	game;
	// int		fila;
	// int		col;

	if (argc != 2)
		return (0);

	ft_memset(&game, 0, sizeof(game));
	ft_read_map(&game, argv);
	ft_check_map_errors(&game, argv);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, (game.map_cols * 50), (game.map_rows * 50), "so_long_game");
	ft_print_graphics_in_window(&game);
	mlx_loop(game.mlx_ptr);

}
