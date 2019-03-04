/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:31:17 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/04 03:18:54 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "list.h"
# include <sys/stat.h>

struct					s_ls
{
	int				flags;
	t_list			*args;
};
typedef struct s_ls		t_ls;

struct					s_arg
{
	char			*path;
	struct stat		stat;

	unsigned char	not_found;
};
typedef struct s_arg	t_arg;

/*
** Flags
*/

# define FLAG_L 0x1
# define FLAG_RR 0x2
# define FLAG_A 0x4
# define FLAG_R 0x8
# define FLAG_T 0x10

# define SUPPORTED_FLAGS "alrRt"

t_ls			*ls_init(void);
t_arg			*arg_init(char *path);
void			arg_destroy(t_arg *arg);
int				get_flag_value(char f);

int				parse(int ac, const char *av[], t_ls *ls);

void			ls_process(t_ls *ls);

void			ft_ls_usage(void);
void			print_ls(t_ls *ls);

#endif