/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:37:09 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/07 15:55:43 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "ft_ls.h"
#include "ftstring.h"

int		lexcmp(t_list *a, t_list *b)
{
	t_arg	*arg1;
	t_arg	*arg2;

	arg1 = (t_arg *)(a->content);
	arg2 = (t_arg *)(b->content);
	return (ft_strcmp(arg1->name, arg2->name));
}
