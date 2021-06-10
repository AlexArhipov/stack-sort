/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:31:11 by avivien           #+#    #+#             */
/*   Updated: 2021/03/18 23:31:14 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	ft_chek_sort(t_all *all)
{
	int	i;
	int	sum;

	sum = 0;
	i = -1;
	while (++i < all->size1 - 1)
		if (all->mal1[i] > all->mal1[i + 1])
			sum++;
	return (sum);
}

int	ft_sert3_1(t_all *all)
{
	if (all->mal1[0] > all->mal1[1] && all->mal1[0] > all->mal1[2] && \
	all->mal1[1] > all->mal1[2])
	{
		ft_ra(all);
		ft_sa(all);
		return (1);
	}
	if (all->mal1[0] > all->mal1[1] && all->mal1[0] > all->mal1[2] && \
	all->mal1[1] < all->mal1[2])
	{
		ft_ra(all);
		return (1);
	}
	return (0);
}

void	ft_sert3(t_all *all)
{
	if (ft_chek_sort(all) == 0)
		return ;
	if (ft_sert3_1(all))
		return ;
	if (all->mal1[0] < all->mal1[1] && all->mal1[0] > all->mal1[2] && \
	all->mal1[1] > all->mal1[2])
	{
		ft_rra(all);
		return ;
	}
	if (all->mal1[0] > all->mal1[1] && all->mal1[0] < all->mal1[2] && \
	all->mal1[1] < all->mal1[2])
	{
		ft_sa(all);
		return ;
	}
	if (all->mal1[0] < all->mal1[1] && all->mal1[0] < all->mal1[2] && \
	all->mal1[1] > all->mal1[2])
	{
		ft_rra(all);
		ft_sa(all);
		return ;
	}
}

void	ft_sert5(t_all *all)
{
	int	vr;
	int	y;

	if (ft_chek_sort(all) == 0)
		return ;
	ft_start_sert5(all);
	y = -1;
	while (++y < 2)
	{
		vr = ft_min_a(all, all->mal2[0]);
		if ((all->size1 / 2) < vr)
			while (all->size1 - vr++ > 0)
				ft_rra(all);
		else
			while (vr-- > 0)
				ft_ra(all);
		ft_pb(all);
	}
	vr = ft_find_min_a(all);
	if ((all->size1 / 2) < vr)
		while (all->size1 - vr++ > 0)
			ft_rra(all);
	else
		while (vr-- > 0)
			ft_ra(all);
}

void	ft_start_sert5(t_all *all)
{
	ft_pa(all);
	ft_pa(all);
	ft_sert3(all);
}
