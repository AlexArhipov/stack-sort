/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:06:33 by avivien           #+#    #+#             */
/*   Updated: 2021/03/20 17:06:38 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	ft_cheks_1(t_all *all, char *line)
{
	if (ft_strncmp(line, "rb", ft_strlen(line)) == 0 \
	&& ft_strlen(line) == 2 && all->size2 > 0)
	{
		ft_rb(all);
		return (1);
	}
	else if (ft_strncmp(line, "rra", ft_strlen(line)) == 0 \
	&& ft_strlen(line) == 3 && all->size1 > 0)
	{
		ft_rra(all);
		return (1);
	}
	else if (ft_strncmp(line, "rrb", ft_strlen(line)) == 0 \
	&& ft_strlen(line) == 3 && all->size2 > 0)
	{
		ft_rrb(all);
		return (1);
	}
	else if (ft_strncmp(line, "rr", ft_strlen(line)) == 0 \
	&& ft_strlen(line) == 2 && all->size2 > 0)
	{
		ft_rr(all);
		return (1);
	}
	return (0);
}

void	*ft_cheks(void *a)
{
	t_all	*all;
	int		i;
	char	*line;

	all = (t_all *)a;
	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		pthread_mutex_lock(&all->mutex);
		if (ft_strncmp(line, "ra", ft_strlen(line)) == 0 \
			&& ft_strlen(line) == 2 && all->size1 > 0)
			ft_ra(all);
		else if (ft_cheks_1(all, line))
			i++;
		else if (ft_cheks_2(all, line))
			i++;
		else
			ft_error();
		free(line);
	}
	free(line);
	return (NULL);
}

int	ft_cheks_2(t_all *all, char *line)
{
	if (ft_strncmp(line, "rrr", ft_strlen(line)) == 0 \
	&& ft_strlen(line) == 3 && all->size2 > 0)
	{
		ft_rrr(all);
		return (1);
	}
	else if (ft_strncmp(line, "sa", ft_strlen(line)) == 0 \
	&& ft_strlen(line) == 2 && all->size1 > 0)
	{
		ft_sa(all);
		return (1);
	}
	else if (ft_strncmp(line, "pb", ft_strlen(line)) == 0 \
	&& ft_strlen(line) == 2 && all->size1 > 0)
	{
		ft_pa(all);
		return (1);
	}
	else if (ft_strncmp(line, "pa", ft_strlen(line)) == 0 \
	&& ft_strlen(line) == 2 && all->size2 > 0)
	{
		ft_pb(all);
		return (1);
	}
	return (0);
}

void	ft_cheks_mass(t_all *all)
{
	pthread_t	thread;

	pthread_mutex_init(&all->mutex, 0);
	pthread_create(&thread, 0, &ft_cheks, all);
	pthread_detach(thread);
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, 1200, 800, "Sort");
	mlx_hook(all->win, 17, (0), &ft_exit, all);
	mlx_loop_hook(all->mlx, &ft_drow, all);
	mlx_loop(all->mlx);
}
