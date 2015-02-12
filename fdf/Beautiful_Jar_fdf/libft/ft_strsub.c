/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:50:53 by bbeaujar          #+#    #+#             */
/*   Updated: 2014/11/18 16:28:01 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (!s)
		return (NULL);
	if ((str = (char *)malloc(sizeof(char) * (len + 1))))
	{
		i = start;
		j = 0;
		while (i < start + len)
			str[j++] = s[i++];
		str[j] = '\0';
	}
	return (str);
}
