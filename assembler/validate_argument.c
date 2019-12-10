/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <lschambe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:13:58 by lschambe          #+#    #+#             */
/*   Updated: 2019/09/21 17:13:57 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		validate_argument(char *f, int i)
{
	while (f[i] && f[i] != '\n')
	{
		if (f[i] == COMMENT_CHAR || f[i] == SEPAR)
			break ;
		if (f[i++] == SEPARATOR_CHAR)
			close_lex(f, i);
	}
}
