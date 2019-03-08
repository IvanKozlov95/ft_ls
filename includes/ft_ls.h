/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:31:17 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/07 19:08:34 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "list.h"
# include "ft_printf.h"

# include <time.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>

struct					s_ls
{
	t_list			*args;
};
typedef struct s_ls		t_ls;

struct					s_dir
{
	char				*path;

	DIR					*dir;
	struct dirent		*file;
};
typedef struct s_dir	t_dir;

struct					s_arg
{
	char			*path;
	char			*name;
	char			is_hidden;
	char			top_level;
	unsigned char	not_found;

	struct stat		stat;
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

# define CURR_DIR "."
# define PARENT_DIR ".."

t_ls					*ls_init(void);

int						parse(int ac, const char *av[], t_ls *ls);

void					ft_ls_usage(void);
void					print_ls(t_ls *ls);

void					arg_destroy(t_arg *arg);
void					get_arg_info(t_list *node);
t_list					*build_arg_list(char *av[]);
t_arg					*arg_init(const char *name, char *dir);
t_list					*convert_name_to_arg(char *name,
	char *dir, int top_level);

void					display_dirs(t_list *node);
void					process_dirs(t_list *args);
t_list					*get_dir_content(t_dir dir);

void					display_files(t_list *node);
char					*build_path(char *dir, char *file_name);

int						lexcmp(t_list *a, t_list *b);
int						timecmp(t_list *a, t_list *b);
void					sort_char_ptr(const char *arr[], int len,
	int (*cmp)(const char *, const char *));

int						get_flag_value(char f);
int						get_set_flag(int set, int get);

char					*get_time(struct stat st);
char					*get_group(struct stat st);
char					*get_owner(struct stat st);
char					get_file_mode(unsigned short st_mode);
void					get_permissions(unsigned short st_mode, char *perm);

#endif
