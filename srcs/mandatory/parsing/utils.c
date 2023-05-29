/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:25:20 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/05/27 14:28:17 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_cords_colors(int line_size, t_matrix *mat, char **line, int i)
{
	t_point	*point;
	int		j;

	j = 0;
	while (line_size-- > 0)
	{
		point = &mat->matrix_points[i][j];
		(*point).z = ft_atoi(line[j]) * -5;
		(*point).x = j * 40;
		(*point).y = i * 40;
		if (ft_strcontain(line[j], ","))
		{
			(*point).color = create_rgb(cal(mat, (*point).z), 255, 255);
		}
		else
			(*point).color = create_rgb(cal(mat, (*point).z), 255, 255);
		j++;
	}
}

void	print_tab_int(int hi, int wi, int **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < hi)
	{
		j = 0;
		while (j < wi)
		{
			ft_printf ("tab[%d][%d] = %d        ", i, j, tab[i][j]);
			j++;
		}
		i++;
		ft_printf("\n");
	}
}

void	print_tab_double(int hi, int wi, double **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < hi)
	{
		j = 0;
		while (j < wi)
		{
			printf ("tab[%d][%d] = %lf        ", i, j, tab[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

void	print_matr_double_z(t_matrix *mat)
{
	int	i;
	int	j;

	i = 0;
	while (i < mat->height)
	{
		j = 0;
		while (j < mat->width)
		{
			printf ("%d  ", mat->matrix_points[i][j].z);
			// if (mat->matrix_points[i][j].color != 0)
			// 	printf ("->{%lf}  ", mat->matrix_points[i][j].color);
			j++;
		}
		i++;
		printf("\n");
	}
}

void	print_matr_double_new_x_y(t_matrix *mat)
{
	int	i;
	int	j;

	i = 0;
	while (i < mat->height)
	{
		j = 0;
		while (j < mat->width)
		{
			printf ("[%d, %d]->[%lf, %lf]   ",i, j, mat->matrix_points[i][j].new_x, mat->matrix_points[i][j].new_y);
			j++;
		}
		i++;
		printf("\n");
	}
}

