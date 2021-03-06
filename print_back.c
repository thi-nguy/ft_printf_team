/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 10:59:46 by thi-nguy          #+#    #+#             */
/*   Updated: 2020/09/09 15:33:13 by thi-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_back(const char *fmt, t_data *t)
{
	int c;

	c = t->i;
	while (fmt[t->i] != '%')
		t->i--;
	while (t->i <= c)
		t->nb_print += write(t->fd, fmt + (t->i)++, 1);
}
