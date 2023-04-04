/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:46:33 by rugrigor          #+#    #+#             */
/*   Updated: 2023/03/22 11:48:44 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	steps(t_list *game)
{
	char	*str;

	str = ft_itoa(game->steps);
	put_grafic(game);
	mlx_string_put(game->mlx, game->win, 14, 7, 0x003300FF, str);
	free(str);
	return (0);
}

void	area(t_list *game, int key)
{
	if (key == 2 || key == 124)
		game->x += 1;
	if (key == 13 || key == 126)
		game->y -= 1;
	if (key == 0 || key == 123)
		game->x -= 1;
	if (key == 1 || key == 125)
		game->y += 1;
}

int	move_player(int key, t_list *game)
{
	if (key == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_clear_window(game->mlx, game->win);
		exit(0);
	}
	if (key == 2 || key == 124)
	{
		game->play = 0;
		player_right(game, key);
	}
	if (key == 13 || key == 126)
		player_up(game, key);
	if (key == 0 || key == 123)
	{
		game->play = 1;
		player_left(game, key);
	}
	if (key == 1 || key == 125)
		player_down(game, key);
	return (0);
}

int	exit1(t_list *game)
{
	int	i;

	i = 0;
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	exit (0);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	game;

	game.steps = 0;
	if (ac == 1)
		write (1, "You don't show a map!\n", 22);
	else if (ac > 2)
		write (1, "Wrong arguments!\n", 17);
	else
	{
		ft_memset(&game, 0, sizeof(t_list));
		if (map_read(&game, av) != 0)
			return (write (1, "Wrong map!\n", 11));
		if (logic(&game, -1, -1) != 0)
			return (write (1, "Wrong map!\n", 11));
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, (game.widthmap * 50),
				(game.heightmap * 50), "so_long");
		put_image(&game);
		put_grafic(&game);
		mlx_hook(game.win, 2, 1L << 0, move_player, &game);
		mlx_hook(game.win, 17, 1L << 0, exit1, &game);
		mlx_loop_hook(game.mlx, coin_move, &game);
		mlx_loop(game.mlx);
	}
}
