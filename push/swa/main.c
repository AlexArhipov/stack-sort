/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:30:01 by avivien           #+#    #+#             */
/*   Updated: 2021/03/18 23:30:07 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	main(int ac, char **ar)
{
	t_all	all;
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	while (ar[++i])
	{
		if (is_digit(ar[i]) == 0)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		s = ft_strjoiner(s, ar[i]);
		s = ft_strjoiner(s, " ");
	}
	all.size1 = ac - 1;
	all.size2 = 0;
	all.count = 0;
	all.mal1 = (int *)malloc(sizeof(int) * all.size1);
	all.mal2 = NULL;
	if (!mai_1(&all, s))
		write(1, "Error\n", 6);
	return (0);
}

int	mai_1(t_all *all, char *s)
{
	int		i;

	i = 0;
	while (i < all->size1)
	{
		if (*s != ' ')
		{
			all->mal1[i++] = (int)ft_atoi(s);
			s = ft_next(s);
		}
		else
			s++;
	}
	if (ft_dublicate(all) == 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	sott(all);
	return (1);
}

void	sott(t_all *all)
{
	if (all->size1 <= 3)
		ft_sert3(all);
	else if (all->size1 <= 5)
		ft_sert5(all);
	else
		ft_sert100(all);
}

int	is_digit(char *s)
{
	long	x;
	int		i;

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

int	ft_dublicate(t_all *all)
{
	int		i;
	int		j;

	i = -1;
	while (++i < all->size1)
	{
		j = i;
		while (++j < all->size1)
		{
			if (all->mal1[i] == all->mal1[j])
				return (0);
		}
	}
	return (1);
}
