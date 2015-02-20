/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:23:54 by bbeaujar          #+#    #+#             */
/*   Updated: 2014/11/18 16:16:46 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		if (n < -9)
		{
			ft_putnbr(-(n / 10));
			ft_putnbr(-(n % 10));
		}
		else
			ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}
