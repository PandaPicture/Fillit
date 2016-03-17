/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:34:57 by amanchon          #+#    #+#             */
/*   Updated: 2016/03/16 16:35:04 by embailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fillit.h"
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

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
	int			fd;
	char		*buff;
	char		*str;
	char		*tmp;
	int			var;

	tetri_list = NULL;
	var = 1;
	if (argc != 2)
	{
		ft_putendl_fd("usage: ./fillit sample_file\n", 2);
		return (1);
	}
	else
	{
		if((fd = open(argv[1], O_RDONLY)) == -1)
		{
			write (1, "Error\n", 6);
			return (0);
		}
		buff = (char*)malloc(sizeof(char) * 256);
		str = ft_strnew(1);
		while ((var = read(fd, buff, 4)) > 0)
		{
			str[var] = '\0';
			tmp = str;
			str = ft_strjoin(str, buff);
			ft_strdel(&tmp);
		}
		create_list(str);
		if (close(fd) == -1)
			write (1, "Error\n", 6);
		free(buff);
	}
	print_map(resolve(tetri_list));
	return (0);
}
