/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:35:22 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/02 20:24:56 by ikozlov          ###   ########.fr       */
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
			return (FALSE);
		// todo: error in else
	}
	return (TRUE);
}

static void	parse_flags(int ac, const char *av[], t_ls *ls)
{
	int		i;
	char	*arg;

	i = -1;
	while (++i < ac && av[i][0] == '-')
	{
		arg = av[i];
		if (parse_flag(arg, ls) == FALSE)
			ft_printf("Error with flags\n");
		else
			ft_printf("awesome\n");
		ft_printf("flags val %d\n", ls->flags);
	}
}

void	parse_args(int ac, const char *av[], t_ls *ls)
{
}

int		parse(int ac, const char *av[], t_ls *ls)
{
	parse_flags(ac, av, ls);
	return (0);
}
