
#include "../include/so_long.h"
#include <stdio.h>

void	print(t_init *init, void *img, int x, int y)
{
	mlx_put_image_to_window(init->mlx, init->win, img,
		32 * x, 32 * y);
}

void	invalid(t_init *init)
{
	ft_printf("Error\nMap : caractere invalide \n");
	free_map(init);
	ft_exit(init);
}

void	print_map(t_init *init, t_count *count, t_move *move)
{
	int	y;
	int	x;

	y = 0;
	while (y < init->height)
	{
		x = 0;
		while (x < init->widht)
		{
			if (init->map[y][x] == '1')
				print_wall(init, x, y);
			else if (init->map[y][x] == '0')
				print_floor(init, x, y);
			else if (init->map[y][x] == 'C')
				print_coin(init, count, x, y);
			else if (init->map[y][x] == 'E')
				print_exit(init, count, x, y);
			else if (init->map[y][x] == 'P')
				print_player(init, move, x, y);
			else
				invalid(init);
			x++;
		}
		y++;
	}
}
