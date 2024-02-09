#include "cub3d.h"
#include "stdio.h"

void	map_validation(char *file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	(void)map;
	if (fd == -1)
	{
		printf("Error: Invalid file\n");
		return ;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		if(ft_strncmp(line, "NO ", 3) == 0)
        {
            printf("NO Texture: %s\n", line + 3);
        }
		free(line);
	}
	close(fd);
}

int	main(int ac, char **av)
{
    t_map    map;

	if (ac == 2)
	{
		printf("Cub3D\n");
		printf("File: %s\n", av[1]);
		map_validation(av[1], &map);
	}
	else
		printf("Error: Invalid number of arguments\n");

	return (0);
}