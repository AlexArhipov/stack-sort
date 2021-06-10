/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:30:27 by avivien           #+#    #+#             */
/*   Updated: 2021/03/18 23:30:30 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	ft_chitovid_ch1(t_all *all, int i)
{
	all->up1 = 0;
	all->sum = 0;
	all->down1 = 0;
	all->up2 = 0;
	all->down2 = 0;
	all->up1 = i;
	all->sum_rr = 0;
	all->sum_rrr = 0;
	all->sum_ra = 0;
	all->sum_rb = 0;
	all->sum_rra = 0;
	all->sum_rrb = 0;
	if ((all->size2 / 2) < i)
	{
		all->down1 = all->size2 - i;
		all->up1 = 0;
	}
	all->up2 = ft_min_a(all, all->mal2[i]);
	if ((all->size1 / 2) < all->up2)
	{
		all->down2 = all->size1 - all->up2;
		all->up2 = 0;
	}
}

void	ft_chitovid_ch2(t_all *all)
{
	if (all->up1 != 0 && all->up2 != 0)
	{
		all->sum += ft_max_sr(all->up1, all->up2);
		all->kto = ft_kto_iz(all->up1, all->up2);
		if (all->kto == 1)
		{
			all->sum_rr = all->up2;
			all->sum_rb = all->up1 - all->up2;
		}
		else
		{
			all->sum_rr = all->up1;
			all->sum_ra = all->up2 - all->up1;
		}
	}
	else
	{
		all->sum += all->up1 + all->up2;
		all->sum_rb = all->up1;
		all->sum_ra = all->up2;
	}
}

void	ft_chitovid_ch3(t_all *all)
{
	if (all->down1 != 0 && all->down2 != 0)
	{
		all->sum += ft_max_sr(all->down1, all->down2);
		all->kto = ft_kto_iz(all->down1, all->down2);
		if (all->kto == 1)
		{
			all->sum_rrr = all->down2;
			all->sum_rrb = all->down1 - all->down2;
		}
		else
		{
			all->sum_rrr = all->down1;
			all->sum_rra = all->down2 - all->down1;
		}
	}
	else
	{
		all->sum += all->down1 + all->down2;
		if (all->down1)
			all->sum_rrb = all->down1;
		if (all->down2)
			all->sum_rra = all->down2;
	}
}

void	ft_chitovid_ch4(t_all *all)
{
	while (all->x_sum_ra-- > 0)
		ft_ra(all);
	while (all->x_sum_rb-- > 0)
		ft_rb(all);
	while (all->x_sum_rra-- > 0)
		ft_rra(all);
	while (all->x_sum_rrb-- > 0)
		ft_rrb(all);
	while (all->x_sum_rr-- > 0)
		ft_rr(all);
	while (all->x_sum_rrr-- > 0)
		ft_rrr(all);
	ft_pb(all);
}

void	ft_chitovid(t_all *all)
{
	int	i;

	i = -1;
	all->min_sum = all->size1;
	while (++i < all->size2)
	{
		ft_chitovid_ch1(all, i);
		ft_chitovid_ch2(all);
		ft_chitovid_ch3(all);
		if (all->sum < all->min_sum)
		{
			all->min_sum = all->sum;
			all->x_sum_ra = all->sum_ra;
			all->x_sum_rb = all->sum_rb;
			all->x_sum_rra = all->sum_rra;
			all->x_sum_rrb = all->sum_rrb;
			all->x_sum_rr = all->sum_rr;
			all->x_sum_rrr = all->sum_rrr;
		}
	}
	ft_chitovid_ch4(all);
}
