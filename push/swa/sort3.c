/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:30:15 by avivien           #+#    #+#             */
/*   Updated: 2021/03/18 23:30:17 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	ft_min_a(t_all *all, int min)
{
	int		i;
	int		tmin;
	int		pos;

	tmin = ft_find_max_a(all);
	tmin = all->mal1[tmin];
	i = -1;
	pos = -1;
	while (++i < all->size1)
	{
		if (min <= all->mal1[i] && tmin >= all->mal1[i])
		{
			tmin = all->mal1[i];
			pos = i;
		}
	}
	if (pos == -1)
		pos = ft_find_min_a(all);
	return (pos);
}

void	ft_sert100(t_all *all)
{
	int		vr;

	if (ft_chek_sort(all) == 0)
		return ;
	vr = ft_find_posled(all);
	if (vr != -1)
	{
		if ((all->size1 / 2) < vr)
			while (vr++ < all->size1 - 1)
				ft_rra(all);
		else
			while (vr-- >= 0)
				ft_ra(all);
	}
	while (all->size1 > 5)
		ft_pa(all);
	ft_sert5(all);
	ft_sert100_2(all);
}

void	ft_sert100_2(t_all *all)
{
	int		i;
	int		vr;

	i = all->size2;
	while (i-- > 0)
		ft_chitovid(all);
	vr = ft_find_min_a(all);
	if ((all->size1 / 2) < vr)
		while (all->size1 - vr++ > 0)
			ft_rra(all);
	else
		while (vr-- > 0)
			ft_ra(all);
}
