/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:31:17 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/02 19:21:20 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

struct		s_ls
{
	int		flags;
};
typedef struct s_ls		t_ls;

/*
** Flags
*/

# define FLAG_L = 0x1
# define FLAG_RR = 0x2
# define FLAG_A = 0x4
# define FLAG_R = 0x8
# define FLAG_T = 0x10


#endif