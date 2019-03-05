/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:19:56 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/04 20:43:03 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

#include <stdlib.h>

char	*build_path(char *dir, char *file_name)
{
	size_t	dlen;
	size_t	flen;
	char	*res;

	dlen = ft_strlen(dir);
	flen = ft_strlen(file_name);
	res = malloc(dlen + flen + 2);
	ft_strcpy(res, dir);
	ft_strcat(res, "/");
	ft_strcat(res, file_name);
	return (res);
}
