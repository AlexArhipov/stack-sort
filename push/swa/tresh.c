/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tresh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:29:53 by avivien           #+#    #+#             */
/*   Updated: 2021/03/18 23:29:55 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	ft_strlen(char *s)
{
	int		i;

	if (s)
	{
		i = 0;
		while (s[i])
			i++;
		return (i);
	}
	return (0);
}

char	*ft_strjoiner(char *s1, char *s2)
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
