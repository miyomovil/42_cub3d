/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:20:06 by antomart          #+#    #+#             */
/*   Updated: 2020/07/15 13:03:14 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_manager(int keycode, t_val *ptr)
{
	if (keycode == ESC)
    	mlx_destroy_window(ptr->mlx, ptr->win);
	if (keycode == FORWARD)
		write_a_red_pixel(ptr);
	if (keycode == LEFT)
		write_a_blue_pixel(ptr);
	if (keycode == RIGHT)
		write_a_white_pixel(ptr);
	return (0);
}

void	init_window(t_val *ptr)
{
    ptr->mlx = mlx_init();
    ptr->win = mlx_new_window(ptr->mlx, ptr->h, ptr->w, "cub3d");
	
	mlx_hook(ptr->win, 2, 1L<<0, key_manager, ptr);
	mlx_loop(ptr->mlx);
}