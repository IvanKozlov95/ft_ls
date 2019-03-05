/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 02:27:50 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/05 02:22:35 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_arg_info(t_list *node)
{
	struct stat		f;
	t_arg			*arg;

	arg = (t_arg *)node->content;
	if (!lstat(arg->path, &f))
	{
		arg->stat = f;
	}
	else
		arg->not_found = 1;
	node->content = arg;
}

void		ls_process(t_ls *ls)
{
	ft_lstiter(ls->args, &process_dirs);
}
