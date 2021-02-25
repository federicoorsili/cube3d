/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:21:43 by forsili           #+#    #+#             */
/*   Updated: 2021/02/19 17:59:55 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		slitta_array(t_hook *h, int i)
{
	int j;
	int k;

	j = i + 1;
	k = i;
	while (h->sprite[k])
	{
		h->sprite[k] = h->sprite[j];
		k++;
		if (h->sprite[j])
			j++;
	}
}

void		elimina_morte(t_hook *h)
{
	int	i;

	i = 0;
	while (h->sprite[i])
	{
		if (!h->sprite[i]->life)
		{
			slitta_array(h, i);
			h->sp->life += 2;
			if (h->sp->life > 100)
				h->sp->life = 100;
		}
		if (h->sprite[i])
			i++;
	}
}

void		free_sprite(t_hook *h)
{
	int i;

	i = 0;
	while (i < h->nsprite)
	{
		free(h->sprite[i]);
		i++;
	}
	free(h->sprite);
}
