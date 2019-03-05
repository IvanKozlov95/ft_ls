/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 03:08:38 by ikozlov           #+#    #+#             */
/*   Updated: 2019/03/05 03:33:48 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		swap(char *arr[], int a, int b)
{
	char	*tmp;

	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

static int		partition(char *arr[], int low, int high,
	int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*pivot;

	pivot = arr[high];
	i = low - 1;
	j = low - 1;
	while (++j < high)
		if (cmp(pivot, arr[j]) >= 0)
			swap(arr, ++i, j);
	swap(arr, i + 1, high);
	return (i + 1);
}

static void		quick_sort(char *arr[], int low, int high,
	int (*cmp)(char *, char *))
{
	int		pi;

	if (low < high)
	{
		pi = partition(arr, low, high, cmp);

		quick_sort(arr, low, pi - 1, cmp);
		quick_sort(arr, pi + 1, high, cmp);
	}
}

void			sort_char_ptr(char *arr[], int len,
	int (*cmp)(char *, char *))
{
	quick_sort(arr, 0, len - 1, cmp);
}

