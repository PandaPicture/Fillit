/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embailla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 14:52:44 by embailla          #+#    #+#             */
/*   Updated: 2016/03/16 16:01:59 by embailla         ###   ########.fr       */
/*   Updated: 2016/03/12 18:36:39 by embailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int			verif_map(char *ptr)
{
	int		i;

	i = 0;
	printf("DEBUG_BEFORE_VERIF\n");
	printf("%s\n", ptr);
	while (ptr[i] != '\0')
	{
		if (ptr[i] != '.' && ptr[i] != '\n' && ptr[i] != '#')
			return (0);
		if (((i % 4) == 4) && ptr[i] != '\n')
			return (0);
		i++;
	}
	printf("DEBUG_AFTER_TEST_MAP\n");
	if (i != 19)
		return (0);
	printf("DEBUG_AFTER_CASE\n");
	if (!(verif_tetri(ptr)))
		return (0);
	printf("DEBUG_AFTER_TETRI_CHECK\n");
	return (1);
}

int			verif_tetri(char *ptr)
{
	int		i;
	char	*s;

	i = 0;
	while (*ptr != '#')
		ptr++;
	s = ptr;
	if (*(s + 1) == '#' && *(s + 2) == '#' && *(s + 7) == '#')
		return (1);
	if (*(s + 1) == '#' && *(s + 2) == '#' && *(s + 6) == '#')
		return (1);
	if (*(s + 1) == '#' && *(s + 2) == '#' && *(s + 5) == '#')
		return (1);
	if (*(s + 1) == '#' && *(s + 4) == '#' && *(s + 5) == '#')
		return (1);
	if (*(s + 1) == '#' && *(s + 2) == '#' && *(s + 3) == '#')
		return (1);
	if (*(s + 1) == '#' && *(s + 5) == '#' && *(s + 6) == '#')
		return (1);
	if (*(s + 1) == '#' && *(s + 6) == '#' && *(s + 7) == '#')
		return (1);
	if (*(s + 5) == '#' && *(s + 9) == '#' && *(s + 10) == '#')
		return (1);
	if (verif2_tetri(s))
		return (1);
	return (0);
}

int			verif2_tetri(char *s)
{
	if (*(s + 4) == '#' && *(s + 5) == '#' && *(s + 10) == '#')
		return (1);
	if (*(s + 1) == '#' && *(s + 6) == '#' && *(s + 11) == '#')
		return (1);
	if (*(s + 5) == '#' && *(s + 6) == '#' && *(s + 11) == '#')
		return (1);
	if (*(s + 5) == '#' && *(s + 10) == '#' && *(s + 15) == '#')
		return (1);
	if (*(s + 4) == '#' && *(s + 5) == '#' && *(s + 9) == '#')
		return (1);
	if (*(s + 5) == '#' && *(s + 6) == '#' && *(s + 7) == '#')
		return (1);
	if (*(s + 4) == '#' && *(s + 5) == '#' && *(s + 6) == '#')
		return (1);
	if (*(s + 3) == '#' && *(s + 4) == '#' && *(s + 5) == '#')
		return (1);
	if (*(s + 1) == '#' && *(s + 5) == '#' && *(s + 10) == '#')
		return (1);
	if (*(s + 5) == '#' && *(s + 6) == '#' && *(s + 10) == '#')
		return (1);
	if (*(s + 5) == '#' && *(s + 10) == '#' && *(s + 11) == '#')
		return (1);
	return (0);
}
