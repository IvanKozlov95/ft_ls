/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:41:39 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/05 05:13:03 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_files(t_list *node)
{
	t_arg	*arg;

	arg = (t_arg *)node->content;
	if (arg->not_found)
		ft_printf("ft_ls: %s: No such file or directory", arg->path);
	else if (!arg->is_hidden
		&& (S_ISREG(arg->stat.st_mode) || !arg->top_level))
		ft_printf("%s\t", arg->name);
}
