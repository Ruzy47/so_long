/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:47:35 by rugrigor          #+#    #+#             */
/*   Updated: 2023/03/22 12:22:16 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_list *game)
{
	int	x;
	int	y;

	game->player1 = mlx_xpm_file_to_image(game->mlx, "./img/p1.xpm", &y, &x);
	game->player2 = mlx_xpm_file_to_image(game->mlx, "./img/p2.xpm", &y, &x);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./img/1.xpm", &y, &x);
	game->exit2 = mlx_xpm_file_to_image(game->mlx, "./img/exit2.xpm", &y, &x);
	game->obelix = mlx_xpm_file_to_image(game->mlx, "./img/ob2.xpm", &y, &x);
	game->coin1 = mlx_xpm_file_to_image(game->mlx, "./img/coin/1.xpm", &y, &x);
	game->coin2 = mlx_xpm_file_to_image(game->mlx, "./img/coin/2.xpm", &y, &x);
	game->coin3 = mlx_xpm_file_to_image(game->mlx, "./img/coin/3.xpm", &y, &x);
	game->coin4 = mlx_xpm_file_to_image(game->mlx, "./img/coin/4.xpm", &y, &x);
	game->coin5 = mlx_xpm_file_to_image(game->mlx, "./img/coin/5.xpm", &y, &x);
	game->coin6 = mlx_xpm_file_to_image(game->mlx, "./img/coin/6.xpm", &y, &x);
	game->enemy = mlx_xpm_file_to_image(game->mlx, "./img/enemy1.xpm", &y, &x);
	game->bg = mlx_xpm_file_to_image(game->mlx, "./img/4.xpm", &y, &x);
	game->border = mlx_xpm_file_to_image(game->mlx, "./img/3.xpm", &y, &x);
}

void	coins(t_list *game)
{
	if (game->coins == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->bg, game->a * 50, game->b * 50);
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit2, game->a * 50, game->b * 50);
		mlx_put_image_to_window(game->mlx, game->win,
			game->obelix, game->a * 50, game->b * 50);
	}
}

void	coin_exit(t_list *game)
{
	if (game->coins == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit2, game->a * 50, game->b * 50);
		mlx_put_image_to_window(game->mlx, game->win,
			game->obelix, game->a * 50, game->b * 50);
	}
	else if (game->coins != 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit, game->a * 50, game->b * 50);
}

void	img_to_win(t_list *game, int y, int x)
{
	coins(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->bg, x * 50, y * 50);
	if (x == game->a && y == game->b && x != 0)
		coin_exit(game);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->border, x * 50, y * 50);
	if (game->map[y][x] == 'E')
		coin_exit(game);
	if (game->map[y][x] == 'P')
	{
		if (game->play == 1)
			mlx_put_image_to_window(game->mlx, game->win,
				game->player1, x * 50, y * 50);
		if (game->play == 0)
			mlx_put_image_to_window(game->mlx, game->win,
				game->player2, x * 50, y * 50);
	}
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->coin1, x * 50, y * 50);
	if (game->map[y][x] == 'N')
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemy, x * 50, y * 50);
}

void	put_grafic(t_list *game)
{
	int	y;
	int	x;

	mlx_clear_window (game->mlx, game->win);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->x = x;
				game->y = y;
			}
			if (game->map[y][x] == 'E')
			{
				game->a = x;
				game->b = y;
			}
			img_to_win(game, y, x);
			x++;
		}
		y++;
	}
}
