/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:24:44 by amanchon          #+#    #+#             */
/*   Updated: 2016/03/16 15:37:25 by embailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

char		**tetri(char **tmp, t_point *min, t_tetri *t)
{

	int		x;
	int		y;
	int 	var;
	char	**buff;

	x = 0;
	var = 0;
	buff = (char**)malloc(sizeof(char**) * (t->height + 1));
	while (var <= t->height)
		buff[var++] = (char*)malloc(sizeof(char*) * (t->width + 1));
	while (x < t->height)
	{
		y = 0;
		while (y < t->width)
		{
			buff[x][y] = tmp[x + min->x][y + min->y];
			y++;
		}
		buff[x][y] = '\0';
		x++;
	}
	buff[x] = NULL;
	return (buff);
}

void		get_dim(t_tetri *t, t_point *min, t_point *max)
{
	t->height = (max->x - min->x) + 1;
	t->width = (max->y - min->y) + 1;
}

t_tetri		*new_tetri(char *str, char c)
{
	printf("DEBUG_NEW_TETRI\n");
	//Couper la fonction car 50 lignes
	t_point		*max;
	t_point		*min;
	t_tetri		*t;
	int			x;
	int			y;
	int			var;
	char		**tmp;

	x = 0;
	y = 0;
	var = 0;
	if (!(verif_map(str)))
		return (NULL);
	printf("DEBUG_AFTER_VERIF\n");
	if (!(max = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	printf("DEBUG_AFTER_MAX\n");
	if (!(min = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	printf("DEBUG_AFTER_MIN\n");
	if (!(t = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	printf("DEBUG_AFTER_T\n");
	tmp = ft_strsplit(str, '\n');
	while (tmp[x])
	{
		while (tmp[x][y])
		{
			if (tmp[x][y] == '#')
			{
				if(var == 0)
				{
					min->x = x;
					min->y = y;
					max->x = x;
					max->y = y;
					var = 1;
				}
				else
				{
					if (min->x > x)
						min->x = x;
					if (min->y > y)
						min->y = y;
					if (max->x < x)
						max->x = x;
					if (max->y < y)
						max->y = y;
				}
			}
			y++;
		}
		x++;
		y = 0;
	}
	printf("DEBUG_AFTER_ASSIGN\n");
	t->letter = c;
	get_dim(t, min, max);
	t->buffer = tetri(tmp, min, t);
	//free tmp & point
	return (t);
}

t_list		*create_list(char *str)
{
	t_tetri 	*t;
	t_list		*list;
	char		**tab;
	char		c;
	int			i;

	i = -1;
	c = 'A';
	list = ft_lstnew(NULL, 42);

	tab = ft_strsplit(str, '\t');
	while (tab[++i])
		;
	while (--i >= 0)
	{
		if (!(t = new_tetri(tab[i], c++)))
			return (NULL);
		//lstdel, avec f(free tetri)
		ft_lstadd(&list, ft_lstnew(t, sizeof(t_tetri)));
	}
	return (list);
}
/*
   int main()
   {
   t_list *l;
   int i = 0;
   char *str = "..#.\n..#.\n..##\n....";
   l = create_list(str);
   return (0);
   }*/
