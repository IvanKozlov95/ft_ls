/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 01:54:09 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/07 16:00:28 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "ft_ls.h"
#include "ft_printf.h"

static void		print_as_sring(t_list *ptr)
{
	t_arg	*tmp;

	tmp = (t_arg *)ptr->content;
	ft_printf("Arg: %s is found? - %d\n", tmp->path, !tmp->not_found);
	ft_printf("Is file %d, is directory: %d\n",
		S_ISREG(tmp->stat.st_mode), S_ISDIR(tmp->stat.st_mode));
}

void			print_ls(t_ls *ls)
{
	ft_printf("BEHOLD THE LS STRUCTURE\n");
	ft_printf("Args:\n");
	ft_lstiter(ls->args, &print_as_sring);
}
