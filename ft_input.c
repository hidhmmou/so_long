/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:30:16 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/27 01:38:02 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handler(int key, t_game *game)
{
	if (key == DOWN)
		ft_move(game, game->map.player.y - 1, game->map.player.x, UP);
	if (key == RIGHT)
		ft_move(game, game->map.player.y, game->map.player.x - 1, LEFT);
	if (key == LEFT)
		ft_move(game, game->map.player.y, game->map.player.x + 1, DOWN);
	if (key == UP)
		ft_move(game, game->map.player.y + 1, game->map.player.x, RIGHT);
	if (key == ESC || key == CLOSE)
		ft_close(game);
	return (0);
}

void	ft_move(t_game *game, int dest_y, int dest_x, int player)
{
	int	old_x;
	int	old_y;

	game->map.player.direction = player;
	old_x = game->map.player.x;
	old_y = game->map.player.y;
	if (game->map.map[dest_x][dest_y] == EXIT && game->map.collectibles == 0)
		ft_win(game);
	else if (game->map.map[dest_x][dest_y] == FLOOR
		|| game->map.map[dest_x][dest_y] == COLLEC)
	{
		game->map.map[old_x][old_y] = FLOOR;
		if (game->map.map[dest_x][dest_y] == COLLEC)
			game->map.collectibles--;
		game->moves++;
		game->map.player.x = dest_x;
		game->map.player.y = dest_y;
		game->map.map[dest_x][dest_y] = PLAYER;
		mlx_clear_window(game->mlx, game->win);
		ft_render(*game);
	}
	else if (game->map.map[dest_x][dest_y] == ENEMY)
		ft_lose(game);
}
