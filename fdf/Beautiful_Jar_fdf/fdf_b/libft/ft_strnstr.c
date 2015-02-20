/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:47:59 by bbeaujar          #+#    #+#             */
/*   Updated: 2014/11/18 16:26:26 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s2[i] != '\0' && s1[j] != '\0' && j < n)
	{
		while (s1[j] == s2[i] && j < n)
		{
			i++;
			j++;
			if (s2[i] == '\0')
				return ((char *)s1 + j - i);
		}
		j = (j - i) + 1;
		i = 0;
	}
	return (NULL);
}
