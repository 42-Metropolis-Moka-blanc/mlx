/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 22:40:21 by bbeaujar          #+#    #+#             */
/*   Updated: 2015/02/09 17:38:53 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_put_line(char *str)
{
	unsigned int		i;
	char				*buf;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	buf = ft_strnew(i);
	ft_strncpy(buf, str, i);
	buf[i] = '\0';
	return (buf);
}

static char		*ft_next_line(char *str)
{
	unsigned int		i;
	char				*buf;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	buf = ft_strdup(str + i + 1);
	ft_strdel(&str);
	return (buf);
}

static int		ft_del(char **save)
{
	ft_strdel(save);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char			*save;
	char				*buff;
	int					ret;
	char				*tmp;

	buff = ft_strnew(BUFF_SIZE + 1);
	if (buff == NULL || line == NULL)
		return (-1);
	save = (save == NULL) ? ft_strnew(1) : save;
	ret = 2;
	while ((ft_strchr(save, '\n') == NULL) && ret > 0)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		buff[ret] = '\0';
		tmp = save;
		save = ft_strjoin(save, buff);
		ft_strdel(&tmp);
	}
	ft_strdel(&buff);
	*line = ft_put_line(save);
	if (ret == 0 && *line[0] == '\0')
		return (ft_del(&save));
	save = ft_next_line(save);
	return (1);
}
