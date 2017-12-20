/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 07:39:11 by ccazuc            #+#    #+#             */
/*   Updated: 2017/12/20 08:47:24 by ccazuc           ###   ########.fr       */
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

int		check_piece_attribut_name(char *s1, char *s2)
{
	int		i;
	size_t	s1_len;

	if ((s1_len = ft_strlen(s1)) > ft_strlen(s2) || s1_len < 3)
		return (0);
	i = -1;
	while (s1[++i] && s2[i])
		if (ft_strncmp_ignrcase(s1, s2, i + 1))
			return (0);
	return (1);
}
