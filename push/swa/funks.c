/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:30:54 by avivien           #+#    #+#             */
/*   Updated: 2021/03/18 23:30:56 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	ft_sa(t_all *all)
{
	int	temp;

	all->count++;
	write(1, "sa\n", 3);
	if (all->size1 >= 2)
	{
		temp = all->mal1[1];
		all->mal1[1] = all->mal1[0];
		all->mal1[0] = temp;
	}
}

void	ft_pa(t_all *all)
{
	int	*tmas1;
	int	*tmas2;
	int	i;

	all->size1--;
	all->size2++;
	all->count++;
	write(1, "pb\n", 3);
	tmas1 = (int *)malloc(all->size1 * sizeof(int));
	tmas2 = (int *)malloc(all->size2 * sizeof(int));
	i = -1;
	while (++i < all->size1)
		tmas1[i] = all->mal1[i + 1];
	i = 0;
	while (++i < all->size2)
		tmas2[i] = all->mal2[i - 1];
	tmas2[0] = all->mal1[0];
	if (all->size1 + 1 > 0)
		free(all->mal1);
	if (all->size2 > 0)
		free(all->mal2);
	all->mal1 = tmas1;
	all->mal2 = tmas2;
}

void	ft_pb(t_all *all)
{
	int	*tmas1;
	int	*tmas2;
	int	i;

	all->size1++;
	all->size2--;
	all->count++;
	write(1, "pa\n", 3);
	tmas1 = (int *)malloc(all->size1 * sizeof(int));
	tmas2 = (int *)malloc(all->size2 * sizeof(int));
	i = -1;
	while (++i < all->size2)
		tmas2[i] = all->mal2[i + 1];
	i = 0;
	while (++i < all->size1)
		tmas1[i] = all->mal1[i - 1];
	tmas1[0] = all->mal2[0];
	if (all->size1 > 0)
		free(all->mal1);
	if (all->size2 + 1 > 0)
		free(all->mal2);
	all->mal1 = tmas1;
	all->mal2 = tmas2;
}

void	ft_ra(t_all *all)
{
	int	*tmas1;
	int	i;

	all->count++;
	write(1, "ra\n", 3);
	tmas1 = (int *)malloc(all->size1 * sizeof(int));
	tmas1[all->size1 - 1] = all->mal1[0];
	i = 0;
	while (++i < all->size1)
		tmas1[i - 1] = all->mal1[i];
	free(all->mal1);
	all->mal1 = tmas1;
}

void	ft_rb(t_all *all)
{
	int	*tmas2;
	int	i;

	all->count++;
	write(1, "rb\n", 3);
	tmas2 = (int *)malloc(all->size2 * sizeof(int));
	tmas2[all->size2 - 1] = all->mal2[0];
	i = 0;
	while (++i < all->size2)
		tmas2[i - 1] = all->mal2[i];
	free(all->mal2);
	all->mal2 = tmas2;
}
