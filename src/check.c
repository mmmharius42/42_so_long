
#include "../include/so_long.h"

void	check_borders(t_init *init)
{
	int	i;

	i = 0;
	while (i < init->widht)
	{
		if (init->map[0][i] != '1' || init->map[init->height - 1][i] != '1')
		{
			ft_printf("Error\nMap non fermer.\n");
			free_map(init);
			exit(0);
		}
		i++;
	}
	i = 0;
	while (i < init->height)
	{
		if (init->map[i][0] != '1' || init->map[i][init->widht - 1] != '1')
		{
			printf("%d", init->widht);
			ft_printf("Error\nMap non fermer.\n");
			free_map(init);
			exit(0);
		}
		i++;
	}
}

void	check_all(t_init *init)
{
	if (!init->map || init->height <= 0 || init->widht <= 0)
	{
		ft_printf("Error\nLa carte n'est pas correctement initialisée.\n");
		free_map(init);
		exit(0);
	}
	check_format(init);
	check_borders(init);
}

void	check_format(t_init *init)
{
	int	i;
	int	first_line;
	int	actually_line;

	if (init->height == 0)
	{
		ft_printf("Error\nMap non valide.\n");
		free_map(init);
		exit(0);
	}
	first_line = ft_strlen(init->map[0]);
	i = 1;
	while (i < init->height)
	{
		actually_line = ft_strlen(init->map[i]);
		if (actually_line != first_line)
		{
			ft_printf("Error\nMap non valide.\n");
			free_map(init);
			exit(0);
		}
		i++;
	}
}

void	check_count(t_init *init, t_count *count, t_move *move)
{
	if (move->count_player != 1)
	{
		ft_printf("Error\nTu a %d joeur(s).\n", move->count_player);
		ft_exit(init);
	}
	else if (count->count_exit > 1)
	{
		ft_printf("Error\nTrop de sorties.\n");
		ft_exit(init);
	}
	else if (count->count_exit != 1)
	{
		ft_printf("Error\nPas de sortie.");
		ft_exit(init);
	}
}
