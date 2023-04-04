/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:33:46 by rugrigor          #+#    #+#             */
/*   Updated: 2023/03/28 19:33:35 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(t_list *game, int i)
{
	if ((i <= 200 && (game->widthmap < 10 || game->heightmap < 10))
		|| (i <= 1500 && (game->widthmap >= 10 || game->heightmap >= 10)))
		game->coin1 = game->coin1;
	if ((i == 400 && (game->widthmap < 10 || game->heightmap < 10))
		|| (i == 3000 && (game->widthmap >= 10 || game->heightmap >= 10)))
		game->coin1 = game->coin2;
	if ((i == 600 && (game->widthmap < 10 || game->heightmap < 10))
		|| (i == 4500 && (game->widthmap >= 10 || game->heightmap >= 10)))
		game->coin1 = game->coin3;
	if ((i == 800 && (game->widthmap < 10 || game->heightmap < 10))
		|| (i == 6000 && (game->widthmap >= 10 || game->heightmap >= 10)))
		game->coin1 = game->coin4;
	if ((i == 1000 && (game->widthmap < 10 || game->heightmap < 10))
		|| (i == 7500 && (game->widthmap >= 10 || game->heightmap >= 10)))
		game->coin1 = game->coin5;
}

int	coin_move(t_list *game, int x, int y)
{
	static int	i;

	x = -1;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			fill(game, i);
			if ((i == 1200 && (game->widthmap < 10 || game->heightmap < 10))
				|| (i == 9000 && (game->widthmap >= 10
						|| game->heightmap >= 10)))
			{
				game->coin1 = game->coin6;
				i = 0;
			}
			i++;
			img_to_win(game, y, x);
		}
	}
	steps(game);
	return (0);
}
