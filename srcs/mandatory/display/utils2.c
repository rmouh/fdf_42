/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:22:35 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/05/27 14:24:06 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return ;
	i = data->bpp - 8;
	pixel = data->addr + (y * data->len + x * (data->bpp / 8));
	while (i >= 0)
	{
		if (data->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (data->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	min_and_val(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (1);
	return (-1);
}

void	plot_line(t_point p0, t_point p1, t_data *img, int color)
{
	t_coor	coor;
	int		err;

	coor.dx = abs (p1.x - p0.x);
	coor.sx = min_and_val(p0.x, p1.x);
	coor.dy = -abs (p1.y - p0.y);
	coor.sy = min_and_val(p0.y, p1.y);
	err = coor.dx + coor.dy;
	while (1)
	{
		my_mlx_pixel_put(img, p0.x, p0.y, color);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		coor.e2 = 2 * err;
		if (coor.e2 >= coor.dy)
		{
			err += coor.dy;
			p0.x += coor.sx;
		}
		if (coor.e2 <= coor.dx)
		{
			err += coor.dx;
			p0.y += coor.sy;
		}
	}
}

int	ft_abs(int a, int b)
{
	if (a - b < 0)
		return (b - a);
	else
		return (a - b);
}

int	ft_slope(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}
