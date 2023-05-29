/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeUtils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:21:30 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/04/08 16:21:44 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab_int(t_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->height)
		free(tab->tab[i++]);
	free(tab->tab);
	free(tab);
}

void	free_line(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}


void	free_list(t_list **lst)
{
	t_list	*track;
	t_list	*nextt;

	track = *lst;
	*lst = NULL;
	while (track != NULL)
	{
		nextt = track->next;
		free(track->content);
		free(track);
		track = nextt;
	}
}

void	free_matrix(t_matrix *mat)
{
	int			i;

	i = 0;
	while (i < mat->height)
		free(mat->matrix_points[i++]);
	free(mat->matrix_points);
	free(mat);
}
