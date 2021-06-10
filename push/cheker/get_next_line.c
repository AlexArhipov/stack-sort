/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:37:10 by wpersimm          #+#    #+#             */
/*   Updated: 2021/02/08 15:17:59 by wpersimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 10

int	get_next_line(int fd, char **line)
{
	static char	*buf;
	char		bufer[10 + 1];
	int			z;

	z = 1;
	while (!ft_newline(buf, 0) && z)
	{
		z = read(fd, bufer, BUFFER_SIZE);
		if (z < 0)
			return (-1);
		bufer[z] = 0;
		buf = ft_strjoiner(buf, bufer);
		if (!buf)
			return (-1);
	}
	*line = ft_strdupper(buf);
	if (!*line)
		return (-1);
	buf = ft_strduplic(buf);
	if (z != 0 && !buf)
		return (-1);
	if (z != 0)
		return (1);
	return (0);
}
