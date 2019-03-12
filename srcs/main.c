/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:34:18 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/12 11:05:47 by ivankozlov       ###   ########.fr       */
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
	t_list	*args;

	args = parse(ac - 1, av + 1);
	g_arg_count = ft_lstcount(args);
	process_dirs(args);
	return (0);
}
