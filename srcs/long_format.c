/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:39:49 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/07 18:39:51 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <grp.h>
#include <time.h>

#include "ft_ls.h"

char	*get_time(struct stat st)
{
	struct timespec	ts;

	ts = st.st_atimespec;
	return (ctime(&ts.tv_sec));
}

char	*get_group(struct stat st)
{
	struct group	*grp;

	grp = getgrgid(st.st_gid);
	if (grp != NULL)
		return (grp->gr_name);
	return ("  ");
}

char	*get_owner(struct stat st)
{
	struct passwd	*pwd;

	pwd = getpwuid(st.st_uid);
	if (pwd != NULL)
		return (pwd->pw_name);
	else
		return ("  ");
}

void	get_permissions(unsigned short st_mode, char *perm)
{
	perm[0] = (st_mode & S_IRUSR) ? 'r' : '-';
	perm[1] = (st_mode & S_IWUSR) ? 'w' : '-';
	if (st_mode & S_ISUID)
		perm[2] = (st_mode & S_IXUSR) ? 's' : 'S';
	else
		perm[2] = (st_mode & S_IXUSR) ? 'x' : '-';
	perm[3] = (st_mode & S_IRGRP) ? 'r' : '-';
	perm[4] = (st_mode & S_IWGRP) ? 'w' : '-';
	if (st_mode & S_ISGID)
		perm[5] = (st_mode & S_IXGRP) ? 's' : 'S';
	else
		perm[5] = (st_mode & S_IXGRP) ? 'x' : '-';
	perm[6] = (st_mode & S_IROTH) ? 'r' : '-';
	perm[7] = (st_mode & S_IWOTH) ? 'w' : '-';
	if (st_mode & S_ISVTX)
		perm[8] = (st_mode & S_IXOTH) ? 't' : 'T';
	else
		perm[8] = (st_mode & S_IXOTH) ? 'x' : '-';
	perm[9] = 0;
}

char	get_file_mode(unsigned short st_mode)
{
	char	mode;

	if (S_ISREG(st_mode))
		mode = '-';
	else if (S_ISDIR(st_mode))
		mode = 'd';
	else if (S_ISCHR(st_mode))
		mode = 'c';
	else if (S_ISBLK(st_mode))
		mode = 'b';
	else if (S_ISFIFO(st_mode))
		mode = 'p';
	else if (S_ISLNK(st_mode))
		mode = 'l';
	else if (S_ISSOCK(st_mode))
		mode = 's';
	else
		mode = '?';
	return (mode);
}
