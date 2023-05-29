/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc_nature.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:53:05 by rmouhoub          #+#    #+#             */
/*   Updated: 2023/05/24 20:01:19 by rmouhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/*
    Question:       what is the nature of the calloc
*/

typedef struct  s_chaud
{
    double  a;
    int     b;
    float   c;
    char    d;
    char    *e;
    t_list  *f;
}   t_chaud;

int main(void)
{
    t_chaud *chaud;

    chaud = malloc(sizeof(t_chaud));

    free (chaud);

    return (0);
}