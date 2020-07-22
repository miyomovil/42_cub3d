/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:20:06 by antomart          #+#    #+#             */
/*   Updated: 2020/07/22 08:48:49 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_manager(int keycode, t_val *ptr)
{
	if (keycode == ESC)
	{
    	mlx_destroy_window(ptr->mlx, ptr->win);
	}
	if (keycode == FORWARD)
	{
		ptr->img = mlx_new_image(ptr->mlx, 1920, 1080);
		ptr->addr = mlx_get_data_addr(ptr->img, &ptr->bits_per_pixel, &ptr->line_length, &ptr->endian);
		verLine_image(70, 1, ptr->w -1, ptr, 0x0000FF00);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	}
	if (keycode == LEFT)
	{
		ptr->img = mlx_new_image(ptr->mlx, 1920, 1080);
		ptr->addr = mlx_get_data_addr(ptr->img, &ptr->bits_per_pixel, &ptr->line_length, &ptr->endian);
		verLine_image(1, 1, ptr->w -1, ptr, 0x000000FF);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	}
	if (keycode == RIGHT)
	{
		ptr->img = mlx_new_image(ptr->mlx, 1920, 1080);
		ptr->addr = mlx_get_data_addr(ptr->img, &ptr->bits_per_pixel, &ptr->line_length, &ptr->endian);
		verLine_image(50, 1, ptr->w -1, ptr, 0x00FFFFFF);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	}
	if (keycode == SPACE)
	{
		ptr->img = mlx_new_image(ptr->mlx, 1920, 1080);
		ptr->addr = mlx_get_data_addr(ptr->img, &ptr->bits_per_pixel, &ptr->line_length, &ptr->endian);
		verLine_image(300, 1, ptr->w -1, ptr, 0x0000FF00);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	}
	return (0);
}

void	init_window(t_val *ptr)
{
	ft_printf("\n ptr->w = %d", ptr->w);
	ft_printf("\n ptr->h = %d", ptr->h);
	ft_printf("\n ptr->playx = %d", ptr->playx);
	ft_printf("\n ptr->playy = %d", ptr->playy);
	ft_printf("\n pos playx playy %c", ptr->map[ptr->playy][ptr->playx]);
    ptr->mlx = mlx_init();
    ptr->win = mlx_new_window(ptr->mlx, ptr->h, ptr->w, "cub3d");
	
	mlx_hook(ptr->win, 2, 1L<<0, key_manager, ptr);
	mlx_loop(ptr->mlx);
}