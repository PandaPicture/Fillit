/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:23:25 by amanchon          #+#    #+#             */
/*   Updated: 2016/03/12 19:02:14 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

typedef struct		s_point
{
	int			x;
	int			y;
}					t_point;
typedef struct		s_map
{
	int		size;
	char	**data;
}					t_map;

typedef struct		s_tetri
{
	int			height;
	int			width;
	char		**buffer;
}					t_tetri;

t_map		*new_map(int size);
void		free_map(t_map **map);
void		print_map(t_map *map);
int			get_mini_map_size(int nb);
t_point		*new_point(int x, int y);
t_tetri		*new_tetri(char *str, char c);
t_list		*create_list(char *str);
void		print_tetri_list(t_list *l);
int			set_value(t_tetri *t, t_map *m, t_point *p, char c);
int			place_tetri(t_tetri *t, t_map *m, t_point *p);

#endif
