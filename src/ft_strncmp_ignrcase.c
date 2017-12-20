/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_ignrcase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 08:12:26 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/20 08:43:33 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	cmp(unsigned char c1, unsigned char c2)
{
	if (!ft_isalpha(c1) || !ft_isalpha(c2))
		return (0);
	return (c1 == c2 || c1 + 32 == c2 || c1 - 32 == c2 ? 1 : 0);
}

int			ft_strncmp_ignrcase(char *s1, char *s2, int n)
{
	int i;

	i = -1;
	while (s1[++i] && s2[i] && i < n)
		if (!cmp((unsigned char)s1[i], (unsigned char)s2[i]))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	if (s2[i] && i < n)
		return (-(unsigned char)s2[i]);
	if (s1[i] && i < n)
		return ((unsigned char)s1[i]);
	return (0);
}
