/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:16:50 by rugrigor          #+#    #+#             */
/*   Updated: 2023/03/20 19:51:10 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checker(char **map, t_list *game, int n, int i)
{
	while (map[++n])
	{
		i = -1;
		while (map[n][++i])
		{
			if (map[n][i] == 'C')
				game->coins += 1;
			if (map[n][i] == 'P')
				game->p += 1;
			if (map[n][i] == 'E')
				game->e += 1;
		}
	}
	n--;
	if (game->n != n)
		return (1);
	if (game->p != 1 || game->e != 1 || game->coins == 0)
		return (1);
	return (0);
}

int	check(char **map)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'P'
				&& map[y][x] != 'E' && map[y][x] != 'C' && map[y][x] != 'N')
				return (1);
		}
	}
	return (0);
}

int	wrong_map(char **map, int i, int n, int x)
{
	while (map[++n])
	{
		i = -1;
		while (map[n][++i])
			if (map[0][i] != '1' || map[n][0] != '1')
				return (1);
		i -= 1;
		if (x == 0)
			x = i;
		if (map[n][i] != '1' || x != i)
			return (1);
		x = i;
	}
	i = -1;
	while (map[n - 1][++i])
		if (map[n - 1][i] != '1')
			return (1);
	return (0);
}

int	general_error(t_list *game, char **map)
{
	if (wrong_map(map, -1, -1, 0) != 0 || checker(map, game, -1, -1) != 0
		|| check(map) != 0)
		return (1);
	return (0);
}
