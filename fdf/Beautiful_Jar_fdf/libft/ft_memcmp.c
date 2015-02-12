/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:17:26 by bbeaujar          #+#    #+#             */
/*   Updated: 2014/11/18 16:04:51 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*t1;
	char		*t2;

	i = 0;
	t1 = (char *)s1;
	t2 = (char *)s2;
	if (n != 0)
	{
		while (i < n - 1 && t1[i] == t2[i])
			i++;
		return ((unsigned char)t1[i] - (unsigned char)t2[i]);
	}
	else
		return (0);
}
