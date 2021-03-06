/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 18:10:34 by amanchon          #+#    #+#             */
/*   Updated: 2016/03/16 15:47:24 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


void	del_tetri(void *content, size_t size)
{
	int		i;
	t_tetri	*t;

	i = 0;
	t = (t_tetri*)content;
	while (i < t->height)
	{
		ft_strdel(&t->buffer[i]);
	}
	free(t->buffer);
	t->buffer = NULL;
	free(t);
	t = NULL;
}

void	free_list(t_list *l)
{
	void (*del)(void*, size_t);
	del = del_tetri;
	ft_lstdel(&l, *del);
}

int main()
{
	t_list *l = create_list("####\n\t#\n#\n#\n#\n");
	printf("%p", l);
	free_list(l);
	printf("%p", l);
}
