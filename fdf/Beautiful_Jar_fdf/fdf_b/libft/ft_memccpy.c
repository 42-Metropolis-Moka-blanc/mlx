/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:15:58 by bbeaujar          #+#    #+#             */
/*   Updated: 2015/01/12 16:13:57 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *((unsigned char *)s2 + i) != (unsigned char)c)
	{
		*((unsigned char *)s1 + i) = *((unsigned char *)s2 + i);
		i++;
	}
	if (i == n)
		return (NULL);
	else
	{
		*((unsigned char *)s1 + i) = *((unsigned char *)s2 + i);
		return ((unsigned char *)s1 + i + 1);
	}
}
