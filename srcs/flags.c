/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 04:26:39 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/07 18:46:05 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ftstring.h"

int		get_set_flag(int set, int get)
{
	static int		flags = 0;

	if (set)
		flags |= set;
	return (flags & get);
}

int		get_flag_value(char f)
{
	static const int	flags_values[5] = { FLAG_A, FLAG_L,\
		FLAG_R, FLAG_RR, FLAG_T };
	int					pos;

	pos = ft_strchri(SUPPORTED_FLAGS, f);
	return (pos >= 0 ? flags_values[pos] : -1);
}
