/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 07:39:11 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/16 07:49:04 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char	*replace_tab_by_space(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '\t')
			str[i] = ' ';
	return (str);
}

void	free_2d_array(char **str)
{
	int		i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
