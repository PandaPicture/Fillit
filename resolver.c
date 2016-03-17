/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 15:23:20 by amanchon          #+#    #+#             */
/*   Updated: 2016/03/17 14:11:31 by embailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_mini_map_size(int nb)
{
	int		size;

	nb *= 4;
	size = 0;
	while (size * size < nb)
		size++;
	return (size);
}

int		try_to_fill(t_map *m, t_list *l)
{
	t_tetri		*t;
	t_point		*p;

	p = NULL;
	if (l == NULL)
		return (1);
	p->x = 0;
	while (p->x < m->size)
	{
		p->y = 0;
		while (p->y < m->size)
		{
			t = (t_tetri*)l->content;
			if (place_tetri(t, m, p))
			{
				if (try_to_fill(m, l + 1))
					return (1);
				set_value(t, m, p, '.');
			}
			p->y++;
		}
		p->x++;
	}
	return (0);
}

int		count_elem(t_list *l)
{
	int		i;

	i = 0;
	while (l->next)
	{
		i++;
		l = l->next;
	}
	return (i);
}
t_map	*resolve(t_list *l)
{
	int		nb_tetri = count_elem(l);
	int		size = get_mini_map_size(nb_tetri);
	t_map	*m = new_map(size);
	while (!try_to_fill(m, l))
	{
		free(m);
		m = new_map(size++);
	}
	return (m);
}
