/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:35:22 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/08 00:21:17 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "ft_ls.h"
#include "ftstring.h"
#include "ft_printf.h"

#include <stdlib.h>

t_bool		parse_flag(const char *arg)
{
	int		i;
	int		flag_val;

	i = 0;
	while (arg[++i])
	{
		flag_val = get_flag_value(arg[i]);
		if (flag_val > 0)
			get_set_flag(flag_val, 0);
		else
		{
			ft_printf("ft_ls: illegal option -- %c\n", arg[i]);
			return (FALSE);
		}
	}
	return (TRUE);
}

static int	parse_flags(int ac, const char *av[])
{
	int			i;
	const char	*arg;

	i = -1;
	while (++i < ac && av[i][0] == '-')
	{
		arg = av[i];
		if (parse_flag(arg) == FALSE)
		{
			ft_ls_usage();
			exit(1);
		}
	}
	return (i);
}

t_list		*parse(int ac, const char *av[])
{
	int		i;
	t_list	*args;

	i = parse_flags(ac, av);
	sort_char_ptr(av + i, ac - i, &ft_strcmp);
	args = build_arg_list((char **)av + i);
	return (args);
}
