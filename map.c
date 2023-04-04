/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:21:49 by rugrigor          #+#    #+#             */
/*   Updated: 2023/03/29 14:33:52 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*spaces(char *str, t_list *game)
{
	int		i;
	int		n;
	char	*ptr;

	i = -1;
	n = 0;
	ptr = ft_strtrim(str, "\n");
	free(str);
	while (ptr[++i])
		if (ptr[i] == '\n')
			n++;
	game->n = n;
	return (ptr);
}

int	height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != 0)
		i++;
	return (i);
}

int	width(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != 0)
		i++;
	return (i);
}

char	**string(t_list *game, char **av)
{
	char	**ptr;
	char	s;
	char	*str;
	int		i;

	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	i = 0;
	while (read(game->fd, &s, 1) > 0)
		i++;
	close(game->fd);
	game->fd = open(av[1], O_RDONLY);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	read(game->fd, str, i);
	str[i] = '\0';
	str = spaces(str, game);
	ptr = ft_split(str, '\n');
	free(str);
	close(game->fd);
	return (ptr);
}

int	map_read(t_list *game, char **av)
{
	char	**map;
	int		i;

	map = string(game, av);
	if (map == NULL)
		return (1);
	game->ptr = string(game, av);
	game->str = string(game, av);
	if (!*map || ft_strstr(av[1], ".ber") != 0)
		return (1);
	if (general_error(game, map) != 0)
		return (1);
	i = 0;
	game->map = map;
	game->heightmap = height(map);
	game->widthmap = width(map);
	return (0);
}
