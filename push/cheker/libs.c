/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:31:24 by avivien           #+#    #+#             */
/*   Updated: 2021/03/18 23:31:28 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

long	ft_atoi(const char *s)
{
	int			z;
	long int	n;
	int			contr;

	z = 1;
	n = 0;
	contr = 0;
	while ((*s == 32) || (*s < 14 && *s > 8))
		s++;
	if ((*s == '+') || (*s == '-'))
		if (*s++ == '-')
			z *= -1;
	while (*s == '0')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s++ - '0');
		if (++contr > 19)
		{
			if (z < 1)
				return (0);
			return (-1);
		}
	}
	return (n * z);
}

char	*ft_next(char *s)
{
	while (*s >= 48 && *s <= 57)
		s++;
	return (s);
}

char	*ft_strjoiner_2(char *s1, char *s2)
{
	char	*mal;
	char	*start_s1;
	char	*start_mal;

	mal = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (mal == NULL)
	{
		free(s1);
		return (NULL);
	}
	start_mal = mal;
	start_s1 = s1;
	if (s1)
	{
		while (*s1)
			*mal++ = *s1++;
		free(start_s1);
	}
	while (*s2)
		*mal++ = *s2++;
	*mal = 0;
	return (start_mal);
}
