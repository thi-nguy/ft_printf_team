/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:04:46 by thi-nguy          #+#    #+#             */
/*   Updated: 2020/09/07 15:10:39 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fillwidth_char(t_data *t)
{
	int i;

	i = t->flag.width - 1;
	while (i > 0)
	{
		t->nb_print += ((t->flag.zero == 1) ?
			write(t->fd, "0", 1) : write(t->fd, " ", 1));
		i--;
	}
}

void	print_char(t_data *t, unsigned char ch)
{
	if (t->flag.minus == 1)
	{
		t->nb_print += write(t->fd, &ch, 1);
		fillwidth_char(t);
	}
	else
	{
		fillwidth_char(t);
		t->nb_print += write(t->fd, &ch, 1);
	}
	t->i++;
}

void	get_char(char type, t_data *t)
{
	unsigned char	ch;
	char			*str;

	t->flag.minus == 1 ? t->flag.zero = 0 : 0;
	if (type == 'c')
	{
		ch = (unsigned char)va_arg(t->valist, int);
		print_char(t, ch);
	}
	else if (type == 's')
	{
		if ((str = (char*)va_arg(t->valist, char*)) != NULL)
		{
			if (!(t->bf = ft_strdup(str)))
				return ;
		}
		else if (!(t->bf = ft_strdup("(null)")))
			return ;
		print_str(t);
	}
}
