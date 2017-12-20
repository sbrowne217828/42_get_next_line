/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labrown <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 23:11:21 by labrown           #+#    #+#             */
/*   Updated: 2017/12/13 20:57:34 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int c, char **v)
{
	char	*line;
	int		fd;
	int		i;

	i = 1;
		while (i <= c)
		{	
			if ((fd = open(v[i++], O_RDONLY)) < 0 && c == 1)
				return (0);
			while (get_next_line(fd, &line) == 1)
			{
				ft_putendl(line);
				free(line);
			}
		}
	return (0);
}
