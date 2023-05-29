/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:24:47 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/05/27 18:10:59 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	ft_draw_line_vertical(t_matrix *mat, int i, int j, t_trans p)
{
	t_point	p1;
	t_point	p2;

	p1.x = i;
	p1.y = j;
	p1.new_x = (int)(mat->matrix_points[i][j].new_x + (2000 / 2 - p.tr_x));
	p1.new_y =(int) (mat->matrix_points[i][j].new_y + (1200 / 2 - p.tr_y));
	p2.x = i + 1;
	p2.y = j;
	p2.new_x =(int) (mat->matrix_points[i + 1][j].new_x + (2000 / 2 - p.tr_x));
	p2.new_y = (int)(mat->matrix_points[i + 1][j].new_y + (1200 / 2 - p.tr_y));
	bresenhams(p1, p2, mat);
}

void	ft_draw_line_horizental(t_matrix *mat, int i, int j, t_trans p)//1
{
	t_point	p1;
	t_point	p2;

	p1.x = i;
	p1.y = j;
	p1.new_x = (int)(mat->matrix_points[i][j].new_x + (2000 / 2 - p.tr_x));
	p1.new_y = (int)(mat->matrix_points[i][j].new_y + (1200 / 2 - p.tr_y));
	p2.x = i;
	p2.y = j + 1;
	p2.new_x =(int)( mat->matrix_points[i][j + 1].new_x + (2000 / 2 - p.tr_x));
	p2.new_y =(int) (mat->matrix_points[i][j + 1].new_y + (1200 / 2 - p.tr_y));
	bresenhams(p1, p2, mat);
}
