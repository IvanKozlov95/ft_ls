/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:34:18 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/07 15:59:44 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_ls.h"
#include "ft_printf.h"

void	ft_ls_usage(void)
{
	ft_printf("usage: ft_ls [-alRrt] [file ...]\n");
}

/*
** ft_ls -Rasd a1 a2 a3 ... aN
*/

int		main(int ac, const char *av[])
{
	t_ls	*ls;

	ls = ls_init();
	parse(ac - 1, av + 1, ls);
	process_dirs(ls->args);
	return (0);
}
