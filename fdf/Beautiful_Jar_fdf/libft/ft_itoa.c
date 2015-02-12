/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:10:47 by bbeaujar          #+#    #+#             */
/*   Updated: 2014/11/18 16:09:27 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		n_sav;
	char	*s;
	int		neg;
	size_t	i;

	n_sav = n;
	neg = n < 0 ? -1 : 1;
	i = 1 + (n < 0);
	while ((n = n / 10))
		i++;
	if ((s = (char *)malloc(sizeof(char) * i)) == NULL)
		return (NULL);
	s[i--] = '\0';
	s[i--] = neg * (n_sav % 10) + '0';
	while ((n_sav = n_sav / 10))
		s[i--] = '0' + neg * (n_sav % 10);
	if (neg < 0)
		s[i] = '-';
	return (s);
}
