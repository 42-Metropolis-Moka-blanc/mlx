/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:14:00 by bbeaujar          #+#    #+#             */
/*   Updated: 2014/11/18 16:10:54 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if ((node = (t_list *)malloc(sizeof(*node))) == NULL)
		return (NULL);
	if (content)
	{
		if ((node->content = (void *)malloc(content_size)) == NULL)
			return (NULL);
		node->content = ft_memmove(node->content, content, content_size);
	}
	else
		node->content = NULL;
	node->content_size = !content ? 0 : content_size;
	node->next = NULL;
	return (node);
}
