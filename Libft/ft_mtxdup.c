/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 01:29:59 by asolis            #+#    #+#             */
/*   Updated: 2017/08/22 01:30:03 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_mtxdup(char **mtx)
{
	char	**res;
	int		len;
	int		i;

	i = -1;
	len = ft_mtxlen(mtx);
	res = (char**)ft_memalloc(sizeof(char) * (len + 1));
	while (mtx[++i] != NULL)
		res[i] = ft_strdup(mtx[i]);
	return (res);
}
