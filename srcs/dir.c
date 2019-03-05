/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:37:10 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/05 02:21:38 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "strings.h"

t_list	*get_dir_content(t_dir dir)
{
	t_list				*res;
	t_arg				*new_arg;
	t_list				*new_node;
	struct dirent		*file;

	res = NULL;
	while ((file = readdir(dir.dir)))
	{
		// if (ft_strcmp(file->d_name, CURR_DIR)
		// 	&& ft_strcmp(file->d_name, PARENT_DIR))
		if (file->d_name[0] != '.')
		{
			new_arg = arg_init(file->d_name);
			new_arg->path = build_path(dir.path, new_arg->name);
			new_node = ft_lstnew(new_arg, sizeof(t_arg));
			res == NULL ? res = new_node : ft_lstaddback(&res, new_node);
			free(new_arg);
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
	// ft_printf("dir cntn: %p %d\n", dir_content, !dir_content);
	if (dir_content)
		process_dirs(dir_content);
}

void		display_dirs(t_list *node)
{
	t_arg	*arg;

	arg = (t_arg *)node->content;
	if (!arg->not_found && S_ISDIR(arg->stat.st_mode))
		display_dir(arg);
}

void		process_dirs(t_list *args)
{
	ft_lstiter(args, &get_arg_info);
	ft_lstiter(args, &display_files);
	ft_printf("\n");
	ft_lstiter(args, &display_dirs);
}
