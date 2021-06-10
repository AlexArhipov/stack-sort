/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:32:25 by avivien           #+#    #+#             */
/*   Updated: 2021/03/18 23:32:27 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"
# include <pthread.h>
# include "minilibx/mlx.h"

typedef struct s_all
{
	int				*mal1;
	int				*mal2;
	int				size1;
	int				size2;
	int				count;
	int				kto;
	int				x_sum_rr;
	int				x_sum_rrr;
	int				x_sum_ra;
	int				x_sum_rb;
	int				x_sum_rra;
	int				x_sum_rrb;
	int				sum_rr;
	int				sum_rrr;
	int				sum_ra;
	int				sum_rb;
	int				sum_rra;
	int				sum_rrb;
	int				up1;
	int				down1;
	int				up2;
	int				down2;
	int				min_sum;
	int				sum;
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				line_l;
	int				bpp;
	int				en;
	pthread_mutex_t	mutex;

}					t_all;
void				ft_sa(t_all *all);
void				ft_pa(t_all *all);
void				ft_ra(t_all *all);
void				ft_rra(t_all *all);
void				ft_sb(t_all *all);
void				ft_pb(t_all *all);
void				ft_rb(t_all *all);
void				ft_rrb(t_all *all);
long				ft_atoi(const char *s);
char				*ft_next(char *s);
void				ft_rr(t_all *all);
void				ft_rrr(t_all *all);
int					mai_1(t_all *all, char *s);
int					is_digit(char *s);
int					ft_dublicate(t_all *all);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strlen(char *s);
void				*ft_cheks(void *a);
void				ft_error(void);
void				ft_cheks_mass(t_all *all);
int					ft_cheks_1(t_all *all, char *line);
int					ft_drow(t_all *all);
void				mmp(t_all *all, int x, int y, int color);
int					ft_exit(t_all *all);
int					ft_cheks_2(t_all *all, char *line);
char				*ft_strjoiner_2(char *s1, char *s2);

#endif
