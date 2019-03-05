/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 03:07:17 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/04 20:40:20 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "strings.h"

#include <stdlib.h>

t_arg	*arg_init(const char *name)
{
	t_arg	*res;

	res = malloc(sizeof(t_arg));
	res->not_found = 0;
	res->is_hidden = name[0] == '.' ? 1 : 0;
	res->name = ft_strdup(name);
	return (res);
}

void	arg_destroy(t_arg *arg)
{
	free(arg->name);
	free(arg->path);
	free(arg);
}
