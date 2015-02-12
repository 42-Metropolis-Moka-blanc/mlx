/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:51:17 by bbeaujar          #+#    #+#             */
/*   Updated: 2014/11/18 16:28:18 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strtrim_resolve(char const *s)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	i = 0;
	start = 0;
	end = 0;
	if (s[i] != '\0')
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (s[i] != '\0')
		{
			start = i;
			while (s[i] != '\0')
				i++;
			i--;
			while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
				i--;
			end = i + 1;
		}
	}
	str = ft_strsub(s, start, end - start);
	return (str);
}

char			*ft_strtrim(char const *s)
{
	char	*str;

	if (!s)
		return (NULL);
	str = ft_strtrim_resolve(s);
	return (str);
}
