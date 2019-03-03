/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:34:18 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/02 20:14:22 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_ls.h"
#include "ft_printf.h"

void	usage(void)
{
	ft_printf("usage: ft_ls [-alRrt] [file ...]\n");
}

/*
** ft_ls -Rasd a1 a2 a3 ... aN
*/

int		main(int ac, const char *av[])
{
	t_ls	*ls;

	if (ac < 2)
	{
		usage();
	}
	ls = ls_init();
	parse(ac - 1, av + 1, ls);
	return (0);
}
