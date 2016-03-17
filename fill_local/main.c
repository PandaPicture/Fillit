/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:34:57 by amanchon          #+#    #+#             */
/*   Updated: 2016/03/15 18:10:19 by amanchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fillit.h"


char	*split_args(char *s)
{
	char		*tmp;
	char		*ret;

	if (!(ret = ft_strdup(s)))
		return (NULL);
	tmp = ret;
	while (*tmp != '\0')
	{
		if (*tmp == '\n' && *(tmp + 1) == '\n')
		{
			*(tmp + 1) = '\t';
		}
		tmp++;
	}
	return (ret);
}

int		main(int argc, char **argv)
{
	t_list		*tetri_list;

	if (argc != 2)
	{
		ft_putendl_fd("usage: ./fillit sample_file\n", 2);
		return (1);
	}
	if (!(tetri_list = create_list(split_args(argv[1]))))
	{
		ft_putendl_fd("error\n", 2);
		return (1);
	}
	print_map(resolve(tetri_list));
	return (0);
}
