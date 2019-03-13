/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:41:39 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/13 14:03:26 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** todo: add extra attributes
*/

void		print_long(t_arg *file)
{
	struct stat		st;
	char			mode;
	char			perm[10];

	st = file->stat;
	mode = get_file_mode(st.st_mode);
	get_permissions(st.st_mode, perm);
	ft_printf("%c%s %2u %s %s %6llu %.16s %s\n", mode, perm, st.st_nlink,
		get_owner(st), get_group(st), st.st_size, get_time(st), file->name);
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
	return ((arg->is_hidden && get_set_flag(0, FLAG_A) && !arg->top_level)
		|| (!arg->is_hidden && (S_ISREG(arg->stat.st_mode) || !arg->top_level)));
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
