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

typedef struct s_all
{
	int			*mal1;
	int			*mal2;
	int			size1;
	int			size2;
	int			count;
	int			kto;
	int			x_sum_rr;
	int			x_sum_rrr;
	int			x_sum_ra;
	int			x_sum_rb;
	int			x_sum_rra;
	int			x_sum_rrb;
	int			sum_rr;
	int			sum_rrr;
	int			sum_ra;
	int			sum_rb;
	int			sum_rra;
	int			sum_rrb;
	int			up1;
	int			down1;
	int			up2;
	int			down2;
	int			min_sum;
	int			max_sum;
	int			sum;
}				t_all;
void			ft_sa(t_all *all);
void			ft_pa(t_all *all);
void			ft_ra(t_all *all);
void			ft_rra(t_all *all);
void			ft_sb(t_all *all);
void			ft_pb(t_all *all);
void			ft_rb(t_all *all);
void			ft_rrb(t_all *all);
long			ft_atoi(const char *s);
char			*ft_next(char *s);
void			ft_sert3(t_all *all);
void			ft_sert5(t_all *all);
int				ft_min_a(t_all *all, int min);
int				ft_find_min_a(t_all *all);
int				ft_find_max_a(t_all *all);
int				ft_find_min_b(t_all *all);
int				ft_find_max_b(t_all *all);
void			ft_sert100(t_all *all);
int				ft_chek_sort(t_all *all);
int				ft_kto_iz(int a, int b);
void			ft_rr(t_all *all);
void			ft_rrr(t_all *all);
char			*ft_strjoiner(char *s1, char *s2);
void			ft_sert100_2(t_all *all);
void			ft_start_sert5(t_all *all);
int				ft_find_posled(t_all *all);
int				ft_max_sr(int a, int b);
void			ft_chitovid(t_all *all);
void			ft_chitovid_ch1(t_all *all, int i);
void			ft_chitovid_ch2(t_all *all);
void			ft_chitovid_ch3(t_all *all);
void			ft_chitovid_ch4(t_all *all);
int				mai_1(t_all *all, char *s);
int				is_digit(char *s);
int				ft_dublicate(t_all *all);
void			sott(t_all *all);

#endif
