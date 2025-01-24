
#include "../include/so_long.h"

int	get_height(char **argv)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFichier mal ouvert\n");
		exit(1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

void	check_args(int argc, char *argv1)
{
	size_t	len;

	if (argc != 2)
	{
		ft_printf("Error\n./so_long map.ber\n");
		exit (0);
	}
	len = strlen(argv1);
	if (strncmp(argv1 + len - 4, ".ber", 4) != 0)
	{
		ft_printf("Error\nMap .ber seulement.\n");
		exit (0);
	}
}

char	**ft_malloc(t_init *init)
{
	char	**map;

	map = malloc(sizeof(char *) * (init->height + 1));
	if (!map)
	{
		ft_printf("Error\nPrblm malloc map\n");
		exit(1);
	}
	return (map);
}

void	parse_map(t_init *init, char **argv)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	init->height = get_height(argv);
	map = ft_malloc(init);
	fd = open(argv[1], O_RDONLY);
	check_fd(fd);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	init->map = map;
	init->widht = ft_strlen(map[0]);
	map_to_visited(init);
}

void	check_fd(int fd)
{
	if (fd == -1)
	{
		ft_printf("Error\nPrblm de fd\n");
		exit(1);
	}
}
