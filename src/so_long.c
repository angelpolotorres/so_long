/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:40:53 by apolo-to          #+#    #+#             */
/*   Updated: 2023/08/16 10:29:50 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_game	game;
	char	*str;

	str = "Movimientos:";
	if (argc != 2)
	{
		printf("Error: Introduce un parámetro correcto y no más de uno.\n");
		return (0);
	}
	if (!ft_check_file(argv[1]))
		return (0);
	ft_memset(&game, 0, sizeof(game));
	ft_read_map(&game, argv);
	ft_check_map_errors(&game, argv);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, (game.map_cols * 50),
			(game.map_rows * 50), "so_long");
	ft_print_graphics_in_window(&game);
	mlx_string_put(game.mlx_ptr, game.win_ptr, 10, 20, 0x4d4282, str);
	mlx_key_hook(game.win_ptr, ft_controls, &game);
	mlx_hook(game.win_ptr, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx_ptr);
}
