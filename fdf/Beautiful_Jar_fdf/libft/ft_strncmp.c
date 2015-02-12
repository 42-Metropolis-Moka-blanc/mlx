/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:44:39 by bbeaujar          #+#    #+#             */
/*   Updated: 2015/01/13 11:55:09 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	if (s1 != NULL || s2 != NULL)
	{
		while (i < n)
		{
			if (s1[i] == '\0' && s2[i] == '\0')
				break ;
			diff = (unsigned char)s1[i] - (unsigned char)s2[i];
			if (diff != 0)
				return (diff);
			i++;
		}
	}
	return (0);
}
