/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antomart <antomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 12:42:35 by antomart          #+#    #+#             */
/*   Updated: 2020/07/16 10:46:40 by antomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_val *ptr, int x, int y, int color)
{
	char	*dst;

	dst = ptr->addr + (y * ptr->line_length + x * (ptr->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void verLine_image(int x, int y0, int y1, t_val *ptr, int color)
{
	int y;
	int y_max;

	if (y0 < y1)
	{
		y = y0;
		y_max = y1;
	}
	else
	{
		y = y1;
		y_max = y0;
	}
	while (y < y_max)
	{
		my_mlx_pixel_put(ptr, x, y, color);
		y++;
	}
}