/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_funk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:31:43 by avivien           #+#    #+#             */
/*   Updated: 2021/03/18 23:31:45 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	ft_find_min_a(t_all *all)
{
	int		i;
	int		pos;
	int		min;

	min = all->mal1[0];
	i = -1;
	pos = 0;
	while (++i < all->size1)
	{
		if (all->mal1[i] < min)
		{
			min = all->mal1[i];
			pos = i;
		}
	}
	return (pos);
}

int	ft_find_max_a(t_all *all)
{
	int		i;
	int		max;
	int		pos;

	max = all->mal1[0];
	i = -1;
	while (++i < all->size1)
	{
		if (all->mal1[i] >= max)
		{
			max = all->mal1[i];
			pos = i;
		}
	}
	return (pos);
}

int	ft_kto_iz(int a, int b)
{
	if (a >= b)
		return (1);
	else
		return (2);
}

int	ft_find_posled(t_all *all)
{
	int		i;
	int		sum;
	int		maxsum;
	int		pos;

	i = -1;
	sum = 0;
	maxsum = 0;
	while (++i < all->size1 - 1)
	{
		if (all->mal1[i] < all->mal1[i + 1])
			sum++;
		else
		{
			if (sum > maxsum)
			{
				maxsum = sum;
				pos = i;
			}
			sum = 0;
		}
	}
	if (maxsum + 1 < 5)
		return (-1);
	return (pos);
}

int	ft_max_sr(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
