/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:31:17 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/02 17:43:01 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

struct ft_ls
{
	int		flags;
};
typedef struct ft_ls t_ls;

/*
*	Flags
*/
# define FLAG_l = 0x1
# define FLAG_R = 0x2
# define FLAG_a = 0x4
# define FLAG_r = 0x8
# define FLAG_t = 0x10


#endif