/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:53:34 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/05/27 18:42:41 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx/mlx.h"
# include<stdio.h> 
# include <fcntl.h>
# include <math.h> 
# include "libft.h"
# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 1200
# endif
# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 2000
# endif

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}				t_data;

typedef struct s_point {
	int		x;
	int		y;
	int		z;
	double	color;
	double	new_x;
	double	new_y;
}				t_point;

typedef struct s_camera{
	double	alpha;
	double	beta;
}				t_camera;

typedef struct s_translation{
	int	x;
	int	y;
}				t_tran;

typedef struct s_bounds{
	double	x_max;
	double	y_max;
	double	z_max;
	double	x_min;
	double	y_min;
	double	z_min;
}				t_bounds;


typedef struct s_matrix{
	t_point	**matrix_points;
	int		width;
	int		height;
	void	*mlx;
	void	*mlx_win;
	// void	*img;
	t_data	imgg;
}				t_matrix;

typedef struct s_tab{
	double	**tab;
	int		height;
	int		width;
}				t_tab;

typedef struct s_trans{
	double		tr_x;
	double		tr_y;
}				t_trans;

typedef struct s_form{
	t_tab		*tab1;
	t_tab		*tab2;
	t_tab		*t;
	t_point		*p;
	t_camera	*cam;
}				t_form;

typedef struct s_coor
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	e2;	
}	t_coor;

/*

		parsing fonctions

*/
void		free_line(char **tab);
void		free_tab_int(t_tab *tab);
void		free_list(t_list **chaine);
void		free_matrix(t_matrix *mat);
t_list		*read_map(char *file, int *nb);
void		get_cords_colors(int line_size, t_matrix *mat, char **line, int i);
int			put_in_tab(int nb, int size_all, t_matrix *mat, t_list *track);
t_matrix	*creat_table(char *file, int *size);
void		print_tab_int(int hi, int wi, int **tab);
void		print_matr_double_z(t_matrix *mat);
void		print_matr_double_new_x_y(t_matrix *mat);
void		print_tab_double(int hi, int wi, double **tab);
void		free_close(t_matrix *mat);
int			create_rgb(int r, int g, int b);
t_bounds	mat_maxs(t_matrix *mat);
t_bounds	mat_mins(t_matrix *mat);
double		cal(t_matrix *mat, double z);



/*
		hexa conversion
*/

double		ft_atoi_base(char *str, int base);
double		conversion(char *p, int sign, int base);
int			is_upper(char c);

/*

		mapping fonctions

*/

void		initialise_p(t_point *p);
// int		malloc_matric_n(int n, int p, int **res);
t_tab		*malloc_matric_n(int n, int p);
t_tab		*multiplicate(double **tab1, double **tab2, int n, int q, int m);
t_camera	*initialize_cam(double alpha, double beta);

		/* multiplications */
void		aux(t_matrix *matrix, t_tab *res, t_form	*x);
t_tab		*first_mult(t_camera *cam, t_tab*tab1, t_tab *tab2);
t_tab		*second_mult(double **tab, t_point *point);
void		third_mult(t_point *point, t_tab *vect, t_tran t);
int			the_formula(t_matrix *matrix, double alpha, double beta);
t_tab		*multiplicate(double **tab1, double **tab2, int n, int q, int m);
void		free_close(t_matrix *mat);


/*			
			display
							*/
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			min_and_val(int nb1, int nb2);
int			ft_slope(int a, int b);
int			absolut (double nb);
int			ft_color(t_point p1, t_point p2, t_point p);
void		ft_set_colors_sep(t_matrix *data, t_point *p1);
void		ft_set_colors(t_matrix *data, t_point *p1, t_point *p2);
void		draw_7(t_matrix *mat, int i, int j, t_trans p);
int			min(double nb1, double nb2);
void		find(t_matrix *mat, t_tran *tr);
void		ft_draw_line_vertical(t_matrix *mat, int i, int j, t_trans p);
void		ft_draw_line_horizental(t_matrix *mat, int i, int j, t_trans p);
void		bresenhams(t_point p1, t_point p2, t_matrix *mat);
void		plot_line(t_point p0, t_point p1, t_data *img, int color);
void		ft_draw_line(t_matrix *mat, int i, int j, int direct);
t_trans		translate(t_point	**mat, int height, int width);
void		ft_pixel(t_data *data, int x, int y, int color);
int			ft_abs(int a, int b);
void		loop(t_matrix	*mat, t_trans	p);

#endif
