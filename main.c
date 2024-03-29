/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:04:12 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/27 23:03:23 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_error(NULL, "only one argument is allowed !");
	ft_check_map(av[1], &game);
	game.mlx = mlx_init();
	ft_win_create(&game);
	ft_render(game);
	mlx_hook(game.win, PRESS, 0, ft_handler, &game);
	mlx_hook(game.win, CLOSE, 0, ft_close, &game);
	mlx_loop_hook(game.mlx, ft_move_animation, &game);
	mlx_loop(game.mlx);
}
