/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:37:09 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/07 19:16:39 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "ft_ls.h"
#include "ftstring.h"

int				lexcmp(t_list *a, t_list *b)
{
	t_arg	*arg1;
	t_arg	*arg2;

	arg1 = (t_arg *)(a->content);
	arg2 = (t_arg *)(b->content);
	return (ft_strcmp(arg1->name, arg2->name));
}

long long int	ft_timecmp(struct timespec t1, struct timespec t2)
{
	long long int	sec_diff;

	sec_diff = t2.tv_sec - t1.tv_sec;
	return (sec_diff == 0 ? t2.tv_nsec - t1.tv_nsec : sec_diff);
}

int				timecmp(t_list *a, t_list *b)
{
	t_arg			*arg1;
	t_arg			*arg2;
	long long int	time_cmp_res;

	arg1 = (t_arg *)(a->content);
	arg2 = (t_arg *)(b->content);
	time_cmp_res = ft_timecmp(arg1->stat.st_mtimespec, arg2->stat.st_mtimespec);
	return (time_cmp_res == 0 ? lexcmp(a, b) : time_cmp_res);
}
