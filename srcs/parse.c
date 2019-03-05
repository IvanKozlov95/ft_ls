/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:35:22 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/05 03:34:06 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "ft_ls.h"
#include "ftstring.h"
#include "ft_printf.h"

#include <stdlib.h>

t_bool	parse_flag(const char *arg, t_ls *ls)
{
	int		i;
	int		flag_val;

	i = 0;
	while (arg[++i])
	{
		flag_val = get_flag_value(arg[i]);
		if (flag_val > 0)
		{
			ls->flags |= flag_val;
			get_set_flag(flag_val, 0);
		}
		else
		{
			ft_printf("ft_ls: illegal option -- %c\n", arg[i]);
			return (FALSE);
		}
	}
	return (TRUE);
}

static int	parse_flags(int ac, const char *av[], t_ls *ls)
{
	int			i;
	const char	*arg;

	i = -1;
	while (++i < ac && av[i][0] == '-')
	{
		arg = av[i];
		if (parse_flag(arg, ls) == FALSE)
		{
			ft_ls_usage();
			exit(1);
		}
		ft_printf("flags val %d\n", ls->flags);
	}
	return (i);
}

void	parse_args(int ac, const char *av[], t_ls *ls)
{
	int			i;
	t_arg		*new_arg;
	t_list		*new_node;

	i = -1;
	ls->args = NULL;
	while (av && av[++i])
	{
		new_arg = arg_init(av[i], NULL);
		new_arg->top_level = 1;
		new_node = ft_lstnew(new_arg, sizeof(t_arg));
		ls->args == NULL ? ls->args = new_node
			: ft_lstaddback(&ls->args, new_node);
		free(new_arg);
	}
	if (ls->args == NULL)
	{
		new_arg = arg_init(".", NULL);
		new_arg->top_level = 1;
		ls->args = ft_lstnew(new_arg, sizeof(t_arg));
		free(new_arg);
	}
}

int		parse(int ac, const char *av[], t_ls *ls)
{
	int		i;

	i = parse_flags(ac, av, ls);
	sort_char_ptr(av + i, ac + i, &ft_strcmp);
	ls->args = build_arg_list((char **)av);
	return (0);
}
