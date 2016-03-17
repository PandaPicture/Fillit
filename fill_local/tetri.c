/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:24:44 by amanchon          #+#    #+#             */
/*   Updated: 2016/03/15 15:34:13 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		*new_point(int x, int y)
{
	t_point		*p;

	if (!(p = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	p->x = x;
	p->y = y;
	return (p);
}

t_tetri		*new_tetri(char *str, char c)
{
	t_tetri		*t;

	if(!(t = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	t->buffer = ft_strsplit(str, '\n');
	//get_dim(t->buffer, t);
	return (t);
}

t_list		*create_list(char *str)
{
	t_list		*list;
	char		**tab;
	char		c;
	int			i;

	i = 0;
	c = 'A';
	list = ft_lstnew(NULL, 42);

	tab = ft_strsplit(str, '\t');
	while (tab[i++ + 1])
		;
	while (--i >= 0)
		ft_lstadd(&list, ft_lstnew(new_tetri(tab[i], c++), sizeof(t_tetri)));
	return (list);
}

void		print_tetri_list(t_list *l)
{
	int i;
	t_tetri *t;

	while (l->next)
	{
		if (!(t = (t_tetri*)l->content))
			ft_putendl("t NULL");
		i = 0;
		while (i < 2)
		{
			ft_putendl(t->buffer[i]);
			i++;
		}
		ft_putendl("\n----\n");
		l = l->next;
	}
}
/*
int main()
{
	t_list *l;
	int i = 0;
	char *str = "..#.\n.#..\t...#\n#...\t....\n..#.\t.#..\n#...";

	//l = create_list(str);
	//print_tetri_list(l);
	get_dim();
	return (0);
}*/
