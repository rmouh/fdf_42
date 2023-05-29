/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:13:20 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/05/27 14:27:24 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

t_bounds	mat_maxs(t_matrix *mat)
{
	int			i;
	int			j;
	t_bounds	b;

	i = 0;
	b.x_max = mat->matrix_points[0][0].x;
	b.y_max = mat->matrix_points[0][0].y;
	b.z_max = mat->matrix_points[0][0].z;
	while (i < mat->height)
	{
		j = 0;
		while (j < mat->width)
		{
			if (b.z_max < mat->matrix_points[i][j].z)
				b.z_max = mat->matrix_points[i][j].z;
			if (b.x_max < mat->matrix_points[i][j].x)
				b.x_max = mat->matrix_points[i][j].x;
			if (b.y_max < mat->matrix_points[i][j].y)
				b.y_max = mat->matrix_points[i][j].y;
			j++;
		}
		i++;
	}
	return (b);
}

t_bounds	mat_mins(t_matrix *mat)
{
	int			i;
	int			j;
	t_bounds	b;

	i = 0;
	b.x_max = mat->matrix_points[0][0].x;
	b.y_max = mat->matrix_points[0][0].y;
	b.z_max = mat->matrix_points[0][0].z;
	while (i < mat->height)
	{
		j = 0;
		while (j < mat->width)
		{
			if (b.z_max > mat->matrix_points[i][j].z)
				b.z_max = mat->matrix_points[i][j].z;
			if (b.x_max > mat->matrix_points[i][j].x)
				b.x_max = mat->matrix_points[i][j].x;
			if (b.y_max > mat->matrix_points[i][j].y)
				b.y_max = mat->matrix_points[i][j].y;
		j++;
		}
	i++;
	}
	return (b);
}

double	cal(t_matrix *mat, double z)
{
	t_bounds	b_min;
	t_bounds	b_max;

	b_max = mat_maxs(mat);
	b_min = mat_mins(mat);
	return (255 * ((z - b_min.z_min) / (b_max.z_max - b_min.z_min)));
}

int	is_upper(char c)
{
	return ((c >= 'A' && c <= 'Z'));
}

