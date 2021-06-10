/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:30:41 by avivien           #+#    #+#             */
/*   Updated: 2021/03/18 23:30:44 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	ft_rra(t_all *all)
{
	int	*tmas1;
	int	i;

	all->count++;
	tmas1 = (int *)malloc(all->size1 * sizeof(int));
	tmas1[0] = all->mal1[all->size1 - 1];
	i = 0;
	while (++i < all->size1)
		tmas1[i] = all->mal1[i - 1];
	free(all->mal1);
	all->mal1 = tmas1;
}

void	ft_rrb(t_all *all)
{
	int	*tmas2;
	int	i;

	all->count++;
	tmas2 = (int *)malloc(all->size2 * sizeof(int));
	tmas2[0] = all->mal2[all->size2 - 1];
	i = 0;
	while (++i < all->size2)
		tmas2[i] = all->mal2[i - 1];
	free(all->mal2);
	all->mal2 = tmas2;
}

void	ft_rr(t_all *all)
{
	int	*tmas1;
	int	*tmas2;
	int	i;

	all->count++;
	tmas1 = (int *)malloc(all->size1 * sizeof(int));
	tmas1[all->size1 - 1] = all->mal1[0];
	i = 0;
	while (++i < all->size1)
		tmas1[i - 1] = all->mal1[i];
	free(all->mal1);
	all->mal1 = tmas1;
	tmas2 = (int *)malloc(all->size2 * sizeof(int));
	tmas2[all->size2 - 1] = all->mal2[0];
	i = 0;
	while (++i < all->size2)
		tmas2[i - 1] = all->mal2[i];
	free(all->mal2);
	all->mal2 = tmas2;
}

void	ft_rrr(t_all *all)
{
	int	*tmas1;
	int	*tmas2;
	int	i;

	all->count++;
	tmas1 = (int *)malloc(all->size1 * sizeof(int));
	tmas1[0] = all->mal1[all->size1 - 1];
	i = 0;
	while (++i < all->size1)
		tmas1[i] = all->mal1[i - 1];
	free(all->mal1);
	all->mal1 = tmas1;
	tmas2 = (int *)malloc(all->size2 * sizeof(int));
	tmas2[0] = all->mal2[all->size2 - 1];
	i = 0;
	while (++i < all->size2)
		tmas2[i] = all->mal2[i - 1];
	free(all->mal2);
	all->mal2 = tmas2;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
