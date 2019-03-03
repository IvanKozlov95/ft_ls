/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:32:33 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/02 20:27:24 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*ls_init(void)
{
	t_ls	*ls;

	ls = malloc(sizeof(t_ls));
	ls->flags = 0;
	return (ls);
}

int		get_flag_value(char f)
{
	static const int	flags_values[5] = { FLAG_A, FLAG_L,\
		FLAG_R, FLAG_RR, FLAG_T };
	int					pos;

	pos = ft_strchri(SUPPORTED_FLAGS, f);
	return (pos > 0 ? flags_values[pos] : -1);
}
