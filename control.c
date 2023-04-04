/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:50:57 by rugrigor          #+#    #+#             */
/*   Updated: 2023/03/22 12:25:07 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	door(t_list *game, int key)
{
	if (game->coins != 0)
	{
		game->map[game->y][game->x] = '0';
		img_to_win(game, game->y, game->x);
		area(game, key);
		game->map[game->y][game->x] = 'P';
		img_to_win(game, game->y, game->x);
		game->steps += 1;
		steps(game);
	}
	else if (game->coins == 0)
	{
		game->map[game->y][game->x] = '0';
		area(game, key);
		game->map[game->y][game->x] = 'P';
		img_to_win(game, game->y, game->x);
		game->steps += 1;
		steps(game);
		write (1, "YOU ARE A WINNER!!\n", 19);
		exit1(game);
	}
}

void	player_up(t_list *game, int key)
{
	if (game->map[game->y - 1][game->x] == 'N')
	{
		write (1, "GAME OVER!!\n", 12);
		exit1(game);
	}
	if (game->map[game->y - 1][game->x] != '1'
		&& game->map[game->y - 1][game->x] != 'E')
	{
		if (game->map[game->y - 1][game->x] == 'C')
			game->coins -= 1;
		game->map[game->y][game->x] = '0';
		img_to_win(game, game->y, game->x);
		game->y -= 1;
		game->map[game->y][game->x] = 'P';
		img_to_win(game, game->y, game->x);
		game->map[game->b][game->a] = 'E';
		game->steps += 1;
		steps(game);
	}
	else if (game->map[game->y - 1][game->x] == 'E')
		door(game, key);
}

void	player_left(t_list *game, int key)
{
	if (game->map[game->y][game->x - 1] == 'N')
	{
		write (1, "GAME OVER!!\n", 12);
		exit1(game);
	}
	if (game->map[game->y][game->x - 1] != '1'
		&& game->map[game->y][game->x - 1] != 'N'
		&& game->map[game->y][game->x - 1] != 'E')
	{
		if (game->map[game->y][game->x - 1] == 'C')
			game->coins -= 1;
		game->map[game->y][game->x] = '0';
		img_to_win(game, game->y, game->x);
		game->x -= 1;
		game->map[game->y][game->x] = 'P';
		img_to_win(game, game->y, game->x);
		game->map[game->b][game->a] = 'E';
		game->steps += 1;
		steps(game);
	}
	else if (game->map[game->y][game->x - 1] == 'E')
		door(game, key);
}

void	player_right(t_list *game, int key)
{
	if (game->map[game->y][game->x + 1] == 'N')
	{
		write (1, "GAME OVER!!\n", 12);
		exit1(game);
	}
	if (game->map[game->y][game->x + 1] != '1'
		&& game->map[game->y][game->x + 1] != 'E')
	{
		if (game->map[game->y][game->x + 1] == 'C')
			game->coins -= 1;
		game->map[game->y][game->x] = '0';
		img_to_win(game, game->y, game->x);
		game->x += 1;
		game->map[game->y][game->x] = 'P';
		img_to_win(game, game->y, game->x);
		game->map[game->b][game->a] = 'E';
		game->steps += 1;
		steps(game);
	}
	else if (game->map[game->y][game->x + 1] == 'E')
		door(game, key);
}

void	player_down(t_list *game, int key)
{
	if (game->map[game->y + 1][game->x] == 'N')
	{
		write (1, "GAME OVER!!\n", 12);
		exit1(game);
	}
	if (game->map[game->y + 1][game->x] != '1'
		&& game->map[game->y + 1][game->x] != 'E')
	{
		if (game->map[game->y + 1][game->x] == 'C')
			game->coins -= 1;
		game->map[game->y][game->x] = '0';
		img_to_win(game, game->y, game->x);
		game->y += 1;
		game->map[game->y][game->x] = 'P';
		img_to_win(game, game->y, game->x);
		game->map[game->b][game->a] = 'E';
		game->steps += 1;
		steps(game);
	}
	else if (game->map[game->y + 1][game->x] == 'E')
		door(game, key);
}
