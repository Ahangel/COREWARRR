/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crath <crath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:31:30 by lschambe          #+#    #+#             */
/*   Updated: 2019/09/25 19:57:44 by crath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		str_len(char *str)
{
	int l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

void	err_ex(char *errors)
{
	write(2, errors, str_len(errors));
	exit(1);
}

int		check_char(char c)
{
	const char	label_chars[] = LABEL_CHARS;
	int			i;

	i = 0;
	while (label_chars[i] != '\0')
	{
		if (label_chars[i++] == c)
			return (1);
	}
	return (0);
}

int		ui_cod(unsigned int n, int q, t_asm *as)
{
	as->code[q] = n >> 24 & 0xff;
	as->code[q + 1] = n >> 16 & 0xff;
	as->code[q + 2] = n >> 8 & 0xff;
	as->code[q + 3] = n & 0xff;
	return (4);
}

int		us_cod(unsigned short n, int q, t_asm *as)
{
	as->code[q] = n >> 8;
	as->code[q + 1] = n & 0xff;
	return (2);
}
