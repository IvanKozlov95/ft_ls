/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 03:07:17 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/05 03:32:07 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ftstring.h"

#include <stdlib.h>

t_arg	*arg_init(const char *name, char *dir)
{
	t_arg	*res;

	res = malloc(sizeof(t_arg));
	res->not_found = 0;
	res->is_hidden = name[0] == '.' ? 1 : 0;
	res->name = ft_strdup(name);
	res->path = dir ? build_path(dir, (char *)name) : ft_strdup(name);
	return (res);
}

void	arg_destroy(t_arg *arg)
{
	free(arg->name);
	free(arg->path);
	free(arg);
}

// todo: add/not add hidden
t_list	*convert_name_to_arg(char *name, char *dir)
{
	int			i;
	t_list		*res;
	t_arg		*new_arg;

	new_arg = arg_init(name, dir);
	res = ft_lstnew(new_arg, sizeof(t_arg));
	free(new_arg);
	return (res);
}

t_list	*build_arg_list(char *av[])
{
	int			i;
	t_list		*res;
	t_list		*new_node;

	i = -1;
	res = NULL;
	while (av && av[++i])
	{
		new_node = convert_name_to_arg(av[i], NULL);
		res == NULL ? res = new_node
			: ft_lstaddback(&res, new_node);
	}
	return (res);
}
