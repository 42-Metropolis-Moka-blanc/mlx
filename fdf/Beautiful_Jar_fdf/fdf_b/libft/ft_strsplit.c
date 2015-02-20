/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:49:39 by bbeaujar          #+#    #+#             */
/*   Updated: 2014/11/18 16:27:07 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strsplit_len(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			len++;
		i++;
	}
	return (len);
}

static char		**ft_for_strsub(char const *s, char c, char **str, int nb_str)
{
	int		i;
	int		j;
	size_t	start;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && nb_str > 0)
		{
			nb_str--;
			start = i;
			len = 0;
			while (s[i] != c && s[i++] != '\0')
				len++;
			str[j++] = ft_strsub(s, start, len);
			i--;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int		nb_str;
	char	**str;

	nb_str = 0;
	if (!s)
		return (NULL);
	nb_str = ft_strsplit_len(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (nb_str + 1))))
		return (NULL);
	str = ft_for_strsub(s, c, str, nb_str);
	return (str);
}
