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
	if (ac <= 1)
		ft_error();
	while (ar[++i])
	{
		if (is_digit(ar[i]) == 0)
			ft_error();
		s = ft_strjoiner_2(s, ar[i]);
		s = ft_strjoiner_2(s, " ");
	}
	all.size1 = ac - 1;
	all.size2 = 0;
	all.count = 0;
	all.mal1 = (int *)malloc(sizeof(int) * all.size1);
	all.mal2 = NULL;
	if (mai_1(&all, s) == 0)
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
		ft_error();
	ft_cheks_mass(all);
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

int	ft_drow(t_all *all)
{
	int	i;
	int	j;

	pthread_mutex_unlock(&all->mutex);
	all->img = mlx_new_image(all->mlx, 1200, 800);
	all->addr = mlx_get_data_addr(all->img, &all->bpp, &all->line_l, &all->en);
	i = -1;
	while (++i < all->size1)
	{
		j = -1;
		while (++j < all->mal1[i])
			mmp(all, i, j, 0xffffff);
	}
	i = -1;
	while (++i < all->size2)
	{
		j = -1;
		while (++j < all->mal2[i])
			mmp(all, i + 500, j, 0xffffff);
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	mlx_destroy_image(all->mlx, all->img);
	return (i);
}
