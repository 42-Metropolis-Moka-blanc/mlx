/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:01:18 by bbeaujar          #+#    #+#             */
/*   Updated: 2015/01/13 11:57:46 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sign(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	sign;

	j = 0;
	sign = 1;
	while (str[j] == ' ' || str[j] == '\t' || str[j] == '\r' || str[j] == '\n'
			|| str[j] == '\v' || str[j] == '\f')
		j++;
	if (!(ft_isdigit(str[j])))
		sign = ft_sign(str[j++]);
	if (ft_isdigit(str[j]))
	{
		i = str[j++] - '0';
		while (str[j] != '\0' && (str[j] >= '0' && str[j] <= '9'))
			i = i * 10 + (str[j++] - '0');
	}
	else
		return (0);
	return (i * sign);
}
