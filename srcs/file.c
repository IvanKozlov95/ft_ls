/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:41:39 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/04 20:41:47 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_files(t_list *node)
{
	t_arg	*arg;

	arg = (t_arg *)node->content;
	if (arg->not_found)
		ft_printf("ft_ls: %s: No such file or directory\n", arg->path);
	else if (!arg->is_hidden)
		ft_printf("%s\n", arg->name);
}
