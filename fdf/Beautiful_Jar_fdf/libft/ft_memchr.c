/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:16:18 by bbeaujar          #+#    #+#             */
/*   Updated: 2015/01/12 16:12:57 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	if (s != NULL)
	{
		while (i < n && *((unsigned char *)s + i) != (unsigned char)c)
			i++;
		if (i < n)
			return ((unsigned char *)s + i);
		else
			return (NULL);
	}
	return (NULL);
}
