/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:19:37 by bbeaujar          #+#    #+#             */
/*   Updated: 2014/11/18 16:07:17 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	if (s1 <= s2)
		return (ft_memcpy(s1, s2, n));
	while (n-- > 0)
		*((char *)s1 + n) = *((char *)s2 + n);
	return (s1);
}
