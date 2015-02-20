/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:40:01 by bbeaujar          #+#    #+#             */
/*   Updated: 2015/01/20 11:35:08 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strjoin2(size_t len1, size_t len2, char *s1, char *s2)
{
	char			*strjoin;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	strjoin = ft_strnew(len1 + len2 + 1);
	while (i < len1)
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (i < len2 + len1)
	{
		strjoin[i] = s2[j];
		i++;
		j++;
	}
	return (strjoin);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*strjoin;

	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	strjoin = ft_strjoin2(len1, len2, (char *)s1, (char *)s2);
	return (strjoin);
}
