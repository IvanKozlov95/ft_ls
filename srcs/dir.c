/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:37:10 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/07 15:39:05 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ftstring.h"

t_list	*get_dir_content(t_dir dir)
{
	t_list				*res;
	t_list				*new_node;
	struct dirent		*file;

	res = NULL;
	while ((file = readdir(dir.dir)))
	{
		if (file->d_name[0] != '.')
		{
			new_node = convert_name_to_arg(file->d_name, dir.path);
			res == NULL ? res = new_node : ft_lstaddback(&res, new_node);
		}
	}
	return (res);
}

static void		display_dir(t_arg *arg)
{
	t_dir		dir_info;
	t_list		*dir_content;

	dir_content = NULL;
	if (!(dir_info.dir = opendir(arg->path)))
		ft_printf("ft_ls: %s: Permission denied\n", arg->path);
	else
	{
		ft_printf("%s:\n", arg->path);
		dir_info.path = arg->path;
		dir_content = get_dir_content(dir_info);
	}
	closedir(dir_info.dir);
	if (dir_content)
		process_dirs(dir_content);
}

void		display_dirs(t_list *node)
{
	t_arg	*arg;

	arg = (t_arg *)node->content;
	if (!arg->not_found && S_ISDIR(arg->stat.st_mode)
		&& (get_set_flag(0, FLAG_RR) || arg->top_level))
		display_dir(arg);
}

void		process_dirs(t_list *args)
{
	static int		first = 1;

	ft_lstiter(args, &get_arg_info);
	ft_lstsort(args, &lexcmp);
	ft_lstiter(args, &display_files);
	if (!first)
		ft_printf("\n\n");
	first = 0;
	ft_lstiter(args, &display_dirs);
	ft_lstdel(&args, &ft_free_content);
}
