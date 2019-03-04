/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 03:07:17 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/04 03:17:46 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "strings.h"

#include <stdlib.h>

t_arg	*arg_init(char *path)
{
	t_arg	*res;

	res = malloc(sizeof(t_arg));
	res->not_found = 0;
	res->path = ft_strdup(path);
	return (res);
}

void	arg_destroy(t_arg *arg)
{
	free(arg->path);
	free(arg);
}
