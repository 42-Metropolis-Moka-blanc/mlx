/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:48:20 by bbeaujar          #+#    #+#             */
/*   Updated: 2014/11/18 16:26:46 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		flag;
	int		match;

	i = 0;
	flag = 0;
	match = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			flag = 1;
			match = i;
		}
		i++;
	}
	if (flag != 0)
		return ((char *)s + match);
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
