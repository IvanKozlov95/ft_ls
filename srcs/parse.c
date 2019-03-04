/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:35:22 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/02 21:35:11 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "ft_ls.h"
#include "strings.h"
#include "ft_printf.h"

t_bool	parse_flag(char *arg, t_ls *ls)
{
	int		i;
	int		flag_val;

	i = 0;
	while (arg[++i])
	{
		flag_val = get_flag_value(arg[i]);
		if (flag_val > 0)
			ls->flags |= flag_val;
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
	int		i;
	char	*arg;

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
	t_list		*args;
	t_list		*new_node;

	i =  -1;
	args = NULL;
	while (av && av[++i])
	{
		new_node = ft_lstnew(av[i], ft_strlen(av[i]));
		args == NULL ? args = new_node : ft_lstaddback(&args, new_node);
		ac++;
	}
	if (args == NULL)
		args = ft_lstnew(".", 2);
	ls->args = args;
}

int		parse(int ac, const char *av[], t_ls *ls)
{
	int		i;

	i = parse_flags(ac, av, ls);
	parse_args(ac, av + i, ls);
	print_ls(ls);
	return (0);
}
