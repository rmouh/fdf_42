/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:10:19 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/05/27 17:04:56 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel(t_data *data, int x, int y, int color)
{
	my_mlx_pixel_put(data, x, y, color);
}

int	ft_color(t_point p1, t_point p2, t_point p)
{
	int		color;
	float	ratio;

	if (p2.new_x - p1.new_x == 0 && p2.new_y - p1.new_y == 0)
		ratio = 1.0;
	else if (p2.new_x - p1.new_x == 0)
		ratio = (float)(p.new_y - p1.new_y) / (p2.new_y - p1.new_y);
	else
		ratio = (float)(p.new_x - p1.new_x) / (p2.new_x - p1.new_x);
	color = (p2.color - p1.color) * ratio + p1.color;
	return (color);
}

void	ft_set_colors_sep(t_matrix *data, t_point *p1)
{
	p1->color = data->matrix_points[p1->x][p1->y].color;
}

void	ft_set_colors(t_matrix *data, t_point *p1, t_point *p2)
{
	ft_set_colors_sep(data, p1);
	ft_set_colors_sep(data, p2);
}

void	bresenhams(t_point p1, t_point p2, t_matrix *mat)
{
	t_point	p;
	int		err;
	int		e;

	p.new_x = p1.new_x;
	p.new_y = p1.new_y;
	err = ft_abs(p2.new_x, p1.new_x) - ft_abs(p2.new_y, p1.new_y);
	ft_set_colors(mat, &p1, &p2);
	while ((int)p.new_x != (int)p2.new_x || (int)p.new_y != (int)p2.new_y)
	{
		ft_pixel(&(mat->imgg), p.new_x, p.new_y, ft_color(p1, p2, p));
		e = 2 * err;
		if (e > -1 * ft_abs(p2.new_y, p1.new_y))
		{
			err -= ft_abs(p2.new_y, p1.new_y);
			p.new_x += ft_slope(p1.new_x, p2.new_x);
		}
		if (e < ft_abs(p2.new_x, p1.new_x))
		{
			err += ft_abs(p2.new_x, p1.new_x);
			p.new_y += ft_slope(p1.new_y, p2.new_y);
		}
	}
	ft_pixel(&(mat->imgg), p.new_x, p.new_y, ft_color(p1, p2, p));
}
