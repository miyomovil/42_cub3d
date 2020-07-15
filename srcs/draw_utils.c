/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:42:35 by antomart          #+#    #+#             */
/*   Updated: 2020/07/15 13:04:18 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_val *ptr, int x, int y, int color)
{
	char	*dst;

	dst = ptr->addr + (y * ptr->line_length + x * (ptr->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	write_a_red_pixel(t_val *ptr)
{
	ptr->img = mlx_new_image(ptr->mlx, 1920, 1080);
	ptr->addr = mlx_get_data_addr(ptr->img, &ptr->bits_per_pixel, &ptr->line_length, &ptr->endian);
	my_mlx_pixel_put(ptr, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
}

void	write_a_blue_pixel(t_val *ptr)
{
	ptr->img = mlx_new_image(ptr->mlx, 1920, 1080);
	ptr->addr = mlx_get_data_addr(ptr->img, &ptr->bits_per_pixel, &ptr->line_length, &ptr->endian);
	my_mlx_pixel_put(ptr, 5, 5, 0x000000FF);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
}

void	write_a_green_pixel(t_val *ptr)
{
	ptr->img = mlx_new_image(ptr->mlx, 1920, 1080);
	ptr->addr = mlx_get_data_addr(ptr->img, &ptr->bits_per_pixel, &ptr->line_length, &ptr->endian);
	my_mlx_pixel_put(ptr, 5, 5, 0x0000FF00);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
}

void	write_a_white_pixel(t_val *ptr)
{
	ptr->img = mlx_new_image(ptr->mlx, 1920, 1080);
	ptr->addr = mlx_get_data_addr(ptr->img, &ptr->bits_per_pixel, &ptr->line_length, &ptr->endian);
	my_mlx_pixel_put(ptr, 5, 5, 0x00FFFFFF);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
}