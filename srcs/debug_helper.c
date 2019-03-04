/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 01:54:09 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/04 02:14:52 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "ft_ls.h"
#include "ft_printf.h"

static void		print_as_sring(t_list *ptr)
{
	ft_printf("%s\n", (char *)ptr->content);
}

void			print_ls(t_ls *ls)
{
	ft_printf("BEHOLD THE LS STRUCTURE\n");
	ft_printf("flags: %d\n", ls->flags);
	ft_printf("Args:\n");
	ft_lstiter(ls->args, &print_as_sring);
}
