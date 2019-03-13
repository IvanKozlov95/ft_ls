/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:41:39 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/13 15:18:47 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "memory.h"

#include <limits.h>

/*
** todo: add extra attributes
*/

void		print_long(t_arg *file)
{
	struct stat		st;
	char			mode;
	char			perm[10];
	char			buf[NAME_MAX + 1];

	st = file->stat;
	ft_bzero(buf, NAME_MAX + 1);
	mode = get_file_mode(st.st_mode);
	get_permissions(st.st_mode, perm);
	ft_printf("%c%s %2u %s %s %6llu %.16s", mode, perm, st.st_nlink,
		get_owner(st), get_group(st), st.st_size, get_time(st));
	if ((readlink(file->path, buf, NAME_MAX)) > 0)
		ft_printf(" %s -> %s\n", file->name, buf);
	else
		ft_printf(" %s\n", file->name);
}

void		display_file(t_list *node)
{
	t_arg		*file;

	file = (t_arg *)(node->content);
	if (!should_display_file(file))
		return ;
	if (get_set_flag(0, FLAG_L))
		print_long(file);
	else if (get_set_flag(0, FLAG_RR))
		ft_printf("%s\t", file->name);
	else
		ft_printf("%s\n", file->name);
}

int			should_display_file(t_arg *arg)
{
	if (arg->not_found)
	{
		ft_printf("ft_ls: %s: No such file or directory\n", arg->path);
		return (0);
	}
	if (arg->is_hidden)
		return (get_set_flag(0, FLAG_A) && !arg->top_level);
	else
		return (S_ISREG(arg->stat.st_mode) || !arg->top_level);
}

void		display_files(t_list *list)
{
	static int		first = 1;

	if (get_set_flag(0, FLAG_L) && !first)
		ft_printf("total: %llu\n", g_total);
	ft_lstiter(list, &display_file);
	if (!first)
		ft_printf("\n");
	first = 0;
}
