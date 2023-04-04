/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:37:20 by rugrigor          #+#    #+#             */
/*   Updated: 2023/03/28 19:24:06 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free2(t_list *game)
{
	int	i;

	i = 0;
	while (game->ptr[i])
	{
		free(game->ptr[i]);
		i++;
	}
	free(game->ptr);
	i = 0;
	while (game->str[i])
	{
		free(game->str[i]);
		i++;
	}
	free(game->str);
}

int	fill_exit(t_list *game, int y, int x)
{
	if (game->ptr[y][x] == 'E')
		return (0);
	if (x >= game->widthmap || y >= game->heightmap || y < 0 || x < 0
		|| game->ptr[y][x] == '1' || game->ptr[y][x] == 'N')
		return (1);
	else if (game->ptr[y][x] == 'E')
		return (0);
	game->ptr[y][x] = '1';
	if (fill_exit(game, y - 1, x) == 0)
		return (0);
	if (fill_exit(game, y + 1, x) == 0)
		return (0);
	if (fill_exit(game, y, x - 1) == 0)
		return (0);
	if (fill_exit(game, y, x + 1) == 0)
		return (0);
	return (1);
}

int	fill_coin(t_list *game, int y, int x, int *coin)
{
	if (x >= game->widthmap || y >= game->heightmap || y < 0 || x < 0
		|| game->str[y][x] == '1' || game->str[y][x] == 'N')
		return (1);
	if (game->str[y][x] == 'C')
		*coin -= 1;
	game->str[y][x] = '1';
	if (*coin == 0)
		return (0);
	if (fill_coin(game, y - 1, x, coin) == 0)
		return (0);
	if (fill_coin(game, y + 1, x, coin) == 0)
		return (0);
	if (fill_coin(game, y, x - 1, coin) == 0)
		return (0);
	if (fill_coin(game, y, x + 1, coin) == 0)
		return (0);
	return (1);
}

int	logic(t_list *game, int y, int x)
{
	int	coin;

	coin = game->coins;
	while (game->ptr[++y])
	{
		x = -1;
		while (game->ptr[y][++x])
		{
			if (game->ptr[y][x] == 'P')
			{
				if (fill_exit(game, y, x) == 0
					&& fill_coin(game, y, x, &coin) == 0)
				{
					free2(game);
					return (0);
				}
			}
		}
	}
	return (1);
}
