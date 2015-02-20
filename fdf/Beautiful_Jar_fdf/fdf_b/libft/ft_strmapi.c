/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:41:26 by bbeaujar          #+#    #+#             */
/*   Updated: 2014/11/18 16:23:33 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (ft_strdup(s));
	str = (char *)malloc((sizeof(char) * ft_strlen(s)) + 1);
	if (str)
	{
		while (s[i] != '\0')
		{
			str[i] = f(i, s[i]);
			i++;
		}
	}
	return (str);
}
