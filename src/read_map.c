/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolo-to <apolo-to@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:09:16 by apolo-to          #+#    #+#             */
/*   Updated: 2023/08/15 12:09:42 by apolo-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

/**
 * This ft receives the name of the file .ber.
 * @param char* file	- The name file.
 * @return int			- 1(ok), 0(error).
*/
int	ft_check_file(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	i = i - 4;
	while (file[i])
	{
		if (file[i] == '.' || file[i] == 'b'
			|| file[i] == 'e' || file[i] == 'r')
			i++;
		else
		{
			printf("Error: Archivo no válido. Adjunte un archivo .ber\n");
			return (0);
		}
	}
	return (1);
}

/**
 * This ft receives a ptr and fills the memory with c the size given by length.
 * @param void* dest	- Pointer of the destiny to fill.
 * @param int c 		- Value to fill the memory.
 * @param size_t length	- Size to fill with the int.
 * @return void*		- A pointer to memory filled.
*/
void	*ft_memset(void *dest, int c, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		((unsigned char *)dest)[i] = (unsigned char) c;
		i++;
	}
	return (dest);
}

/**
 * This ft transform add a new line to game->map using a temporary var.
 * @param t_game* game	- Game structure.
 * @param char* line	- The new line to add.
 * @return int 			- 1(ok), 0(error).
*/
static int	ft_save_line_map(t_game *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->map_rows++;
	temporary = (char **)malloc(sizeof(char *) * (game->map_rows + 1));
	temporary[game->map_rows] = NULL;
	while (i < game->map_rows - 1)
	{
		temporary[i] = game->map[i];
		i ++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

/**
 * This ft recive a map line and count the line width
 * If the end of the line has '\n' doesn`t count this caracter.
 * @param char* map_line	- Pointer to the map line
 * @return int 				- Line width
*/
static int	ft_count_map_cols(char *map_line)
{
	int	map_cols;

	map_cols = 0;
	while (map_line[map_cols] != '\0')
		map_cols ++;
	if (map_line[map_cols - 1] == '\n')
		map_cols --;
	return (map_cols);
}

/**
 * This ft read the map from input and copy to game structure.
 * @param t_game* game	- Pointer to game structure
 * @param char** argv	- Pointer to arguments value recibed from console.
 * @return int			- (1)ok, 0(error).
*/
int	ft_read_map(t_game *game, char **argv)
{
	char	*line_map;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	game->map_rows = 0;
	while (1)
	{
		line_map = get_next_line(game->fd);
		if (!ft_save_line_map(game, line_map))
			break ;
	}
	close(game->fd);
	game->map_cols = ft_count_map_cols(game->map[0]);
	return (1);
}
