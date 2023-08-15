/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:32:20 by apolo-to          #+#    #+#             */
/*   Updated: 2023/08/15 12:56:37 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;
	
	char	**map;
	int		map_rows;
	int		map_cols;
	
	void	*player_img;
	void	*wall_img;
	void	*floor_img;
	void	*collectable_img;
	void	*exit_img;
	
	int		collectable_count;
	int		player_count;
	int		player_row;
	int		player_col;
	int		exit_count;
	int		path_collectable_count;
	int		path_exit_count;
	int		movements;
}	t_game;

int		ft_check_file(char *file);
void	*ft_memset(void *dest, int c, size_t length);
int		ft_read_map(t_game *game, char **argv);
int		ft_check_map_errors(t_game *game, char **argv);
void	ft_check_valid_path(t_game *game);
void	ft_print_graphics_in_window(t_game *game);
int		ft_controls(int key, t_game *game);
void	ft_show_error(t_game *game, int error);
void	ft_free_map(t_game *game);
void	ft_exit(t_game *game);
char	*ft_itoa(int n);
#endif