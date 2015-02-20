/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:45:35 by bbeaujar          #+#    #+#             */
/*   Updated: 2015/01/13 11:59:33 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 != NULL)
	{
		while (s2[i] != '\0' && i < n)
		{
			s1[i] = s2[i];
			i++;
		}
		while (i < n)
		{
			s1[i] = '\0';
			i++;
		}
		return (s1);
	}
	return (NULL);
}
