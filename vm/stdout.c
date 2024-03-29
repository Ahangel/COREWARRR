/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:01:46 by dstracke          #+#    #+#             */
/*   Updated: 2019/12/16 02:34:38 by dstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	err_ex(char *error_message)
{
	int i;

	i = 0;
	while (error_message[i])
		i++;
	write(2, "Error: ", 7);
	write(2, error_message, i);
	exit(1);
}

void	to_show_usage(void)
{
	write(1, "Usage:\n       ./corewar bot1.cor bot2.cor ", 43);
	write(1, "[max MAX_PLAYERS bots]\n", 23);
	write(1, "       to see visualization add ", 32);
	write(1, "[-v (cycle_num)] as first argument\n", 35);
	write(1, "       to see state of the memory after specific cycle add ", 59);
	write(1, "[-dump cycle_num] as first argument\n", 36);
	write(1, "       you can change order of players by adding ", 49);
	write(1, "[-n number] before bot name\n", 28);
}

void	introduction_players(t_vm *vm)
{
	int i;

	ft_printf("Introducing competitors...\n");
	i = 0;
	while (i < vm->number_of_bots)
	{
		ft_printf("* Player %d, weighing %ld bytes, \"%s\" (\"%s\") !\n", i + 1,
			vm->bot[i].size, vm->bot[i].name, vm->bot[i].comment);
		i++;
	}
}

void	dump_memory(t_vm *vm)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			ft_printf("0x%02x%02x : ", i >> 8, i & 0xff);
		ft_printf("%02x ", vm->map[i].val);
		if ((i + 1) % 64 == 0)
			write(1, "\n", 1);
		i++;
	}
}
