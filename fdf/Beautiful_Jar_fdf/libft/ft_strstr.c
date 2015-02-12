/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:50:35 by bbeaujar          #+#    #+#             */
/*   Updated: 2014/11/18 16:27:27 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s2[i] != '\0' && s1[j] != '\0')
	{
		while (s1[j] == s2[i])
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
