/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:47:35 by rugrigor          #+#    #+#             */
/*   Updated: 2023/03/22 12:22:16 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	char	**map;
	char	**ptr;
	char	**str;
	void	*mlx;
	void	*win;
	void	*player1;
	void	*player2;
	void	*exit;
	void	*exit2;
	void	*obelix;
	void	*enemy;
	void	*bg;
	void	*coin1;
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*coin5;
	void	*coin6;
	void	*border;

	int		steps;
	int		frame;
	int		play;
	int		x;
	int		y;
	int		a;
	int		b;
	int		n;
	int		fd;
	int		size;
	int		heightmap;
	int		widthmap;
	int		coins;
	int		p;
	int		e;
}	t_list;

int		map_read(t_list *game, char **av);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_itoa(int n);
int		ft_strstr(char *str, char *to_find);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strdup(const char *str);
char	**string(t_list *game, char **av);
int		general_error(t_list *game, char **map);
void	put_grafic(t_list *game);
void	put_image(t_list *game);
void	img_to_win(t_list *game, int y, int x);
int		move_player(int key, t_list *game);
void	player_down(t_list *game, int key);
void	player_right(t_list *game, int key);
void	player_left(t_list *game, int key);
void	player_up(t_list *game, int key);
void	area(t_list *game, int key);
int		steps(t_list *game);
int		coin_move(t_list *game, int x, int y);
int		exit1(t_list *game);
int		logic(t_list *game, int y, int x);
void	player_move(t_list *game, int y, int x, int key);

#endif
