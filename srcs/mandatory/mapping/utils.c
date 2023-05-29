/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:59:25 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/05/27 18:13:16 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

 //have to freee cam at the end
t_camera	*initialize_cam(double alpha, double beta)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera) * 1);
	if (!cam)
		return (NULL);// mange the null exit 
	cam->alpha = alpha * 3.14 / 180;
	cam->beta = beta * 3.14 / 180;
	return (cam);
}

//have to free res at the end 
t_tab	*first_mult(t_camera *cam, t_tab *tab1, t_tab *tab2)
{
	t_tab	*res;

	tab1 = malloc_matric_n(3, 3);
	if (!tab1)
		return (NULL);
	tab2 = malloc_matric_n(3, 3);
	if (!tab2)
		return (free_tab_int(tab1), NULL);
	tab1->tab[0][0] = 1;
	tab1->tab[1][1] = cos(cam->alpha);
	tab1->tab[1][2] = sin(cam->alpha);
	tab1->tab[2][1] = -sin(cam->alpha);
	tab1->tab[2][2] = cos(cam->alpha);
	tab2->tab[0][0] = cos(cam->beta);
	tab2->tab[0][2] = -sin(cam->beta);
	tab2->tab[1][1] = 1;
	tab2->tab[2][0] = sin(cam->beta);
	tab2->tab[2][2] = cos(cam->beta);
	res = multiplicate(tab1->tab, tab2->tab, 3, 3, 3);
	return (free_tab_int(tab1), free_tab_int(tab2), res);
}

t_tab	*second_mult(double **tab, t_point *point)
{
	t_tab	*vect;
	t_tab	*res;

	vect = malloc_matric_n(3, 1);
	if (!vect)
		return (NULL);
	vect->tab[0][0] = (double)point->x;
	vect->tab[1][0] = (double)point->y;
	vect->tab[2][0] = (double)(point->z);
	res = multiplicate(tab, vect->tab, 3, 1, 3);
	free_tab_int(vect);
	return (res);
}

void	third_mult(t_point *point, t_tab *vect, t_tran t)
{
	t_tab	*tab1;
	t_tab	*res;

	tab1 = malloc_matric_n(3, 3);
	if (!tab1)
		return ;
	tab1->tab[0][0] = 1;
	tab1->tab[1][1] = 1;
	res = multiplicate(tab1->tab, vect->tab, 3, 1, 3);
	free_tab_int(tab1);
	point->new_x = res->tab[0][0];
	point->new_y = res->tab[1][0];
	free_tab_int(res);
	free_tab_int(vect);
}

void	free_close(t_matrix *mat)
{
	mlx_destroy_image(mat->mlx, mat->imgg.img);
	mlx_clear_window(mat->mlx, mat->mlx_win);
	mlx_destroy_window(mat->mlx, mat->mlx_win);
	mlx_destroy_display(mat->mlx);
	free(mat->mlx);
	free_matrix(mat);
	exit(0);
}
