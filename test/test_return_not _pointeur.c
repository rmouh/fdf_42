/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_return_not _pointeur.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:34:39 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/05/26 14:46:41 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_trans{
	double		tr_x;
	double		tr_y;
}				t_trans;

t_trans	translate(int height, int width)
{

	t_trans	p;

	p.tr_x = (height);
	p.tr_y = (width);
	return(p);

}
t_trans f(t_trans p)
{
    p.tr_x= 85;
    return (p);
}
int main()
{
    t_trans pp= translate(4,5);
    pp.tr_x = 0;
    printf("%f   %f\n", pp.tr_x, pp.tr_y);
    t_trans ppp = f(pp);
    // printf("%f   %f\n", ppp.tr_x, ppp.tr_y);
    // printf("%f   %f\n", pp.tr_x, pp.tr_y);

}