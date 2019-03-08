/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 03:07:17 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/07 15:59:35 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ftstring.h"

#include <stdlib.h>

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

t_arg	*arg_init(const char *name, char *dir)
{
	t_arg	*res;

	res = malloc(sizeof(t_arg));
	res->not_found = 0;
	res->is_hidden = name[0] == '.' ? 1 : 0;
	res->name = ft_strdup(name);
	res->path = dir ? build_path(dir, (char *)name) : ft_strdup(name);
	res->top_level = 0;
	return (res);
}

void	arg_destroy(t_arg *arg)
{
	free(arg->name);
	free(arg->path);
	free(arg);
}

// todo: add/not add hidden
t_list	*convert_name_to_arg(char *name, char *dir, int top_level)
{
	int			i;
	t_list		*res;
	t_arg		*new_arg;

	new_arg = arg_init(name, dir);
	new_arg->top_level = top_level;
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
		new_node = convert_name_to_arg(av[i], NULL, 1);
		LST_ADDCREATE(res, new_node);
	}
	if (res == NULL)
		res = convert_name_to_arg(CURR_DIR, NULL, 1);
	return (res);
}
