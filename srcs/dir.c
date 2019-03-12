/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:37:10 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/12 11:14:43 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ftstring.h"

t_list			*get_dir_content(t_dir dir)
{
	t_list				*res;
	t_list				*new_node;
	struct dirent		*file;

	res = NULL;
	while ((file = readdir(dir.dir)))
	{
		if (file->d_name[0] != '.' || get_set_flag(0, FLAG_A))
		{
			new_node = convert_name_to_arg(file->d_name, dir.path, 0);
			LST_ADDCREATE(res, new_node);
		}
	}
	return (res);
}

char			is_special_dir(char *path)
{
	return (ft_strequ(path, CURR_DIR) || ft_strequ(path, PARENT_DIR));
}

static void		display_dir(t_arg *arg)
{
	int			recur;
	t_dir		dir_info;
	t_list		*dir_content;

	dir_content = NULL;
	if (!(dir_info.dir = opendir(arg->path)))
		ft_printf("ft_ls: %s: Permission denied\n", arg->path);
	else if ((is_special_dir(arg->name) && arg->top_level)
		|| !is_special_dir(arg->name))
	{
		if (g_arg_count > 1 || !arg->top_level)
			ft_printf("%s:\n", arg->path);
		dir_info.path = arg->path;
		dir_content = get_dir_content(dir_info);
	}
	closedir(dir_info.dir);
	if (dir_content)
		process_dirs(dir_content);
}

void			display_dirs(t_list *node)
{
	t_arg	*arg;

	arg = (t_arg *)node->content;
	if (!arg->not_found && S_ISDIR(arg->stat.st_mode)
		&& (get_set_flag(0, FLAG_RR) || arg->top_level)) {
			ft_printf("\n");
			display_dir(arg);
		}
}

void			process_dirs(t_list *args)
{
	static int		(*sort_func)(t_list *, t_list *);

	sort_func = get_set_flag(0, FLAG_T) ? &timecmp : &lexcmp;
	ft_lstiter(args, &get_arg_info);
	ft_lstsortascdesc(args, sort_func, !get_set_flag(0, FLAG_R));
	ft_lstiter(args, &display_files);
	ft_printf("\n");
	ft_lstiter(args, &display_dirs);
	ft_lstdel(&args, &arg_list_destroy);
}
