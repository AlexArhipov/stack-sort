/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_funks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:06:45 by avivien           #+#    #+#             */
/*   Updated: 2021/03/20 17:06:46 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	is_digit(char *s)
{
	int		i;
	long	x;

	i = 0;
	x = ft_atoi(s);
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			i++;
		else
			return (0);
		s++;
	}
	if (x > 2147483647 || x < -2147483648)
		return (0);
	return (1);
}

void	mmp(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->addr + (y * all->line_l + x * (all->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_strlen(char *s)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i])
			i++;
		return (i);
	}
	return (0);
}

int	ft_exit(t_all *all)
{
	int	i;

	if (all->size2 != 0)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	i = -1;
	while (++i < all->size1 - 1)
	{
		if (all->mal1[i] > all->mal1[i + 1])
		{
			write(1, "KO\n", 3);
			exit(0);
		}
	}
	write(1, "OK\n", 3);
	exit(0);
}
