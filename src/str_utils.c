/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <lufranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:13:58 by lufranco          #+#    #+#             */
/*   Updated: 2019/01/14 16:13:59 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char		*replace_tab_by_space(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '\t')
			str[i] = ' ';
	return (str);
}

void		free_2d_array(char **str)
{
	int		i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

static int	parse_ref(char *s1, char *s2)
{
	int		i;
	size_t	s1_len;

	if ((s1_len = ft_strlen(s1)) > ft_strlen(s2) || s1_len < 4)
		return (0);
	i = 2;
	while (s1[++i] && s2[i])
		if (ft_strncmp_ignrcase(s1, s2, i + 1))
			return (0);
	return (1);
}

int			check_piece_attribut_name(char *s1, char *s2)
{
	int		i;
	size_t	s1_len;

	if ((s1_len = ft_strlen(s1)) > ft_strlen(s2) || s1_len < 3)
		return (0);
	if (s2[0] == 'r' && s2[1] == 'e' && s2[2] == 'f')
		return (parse_ref(s1, s2));
	i = -1;
	while (s1[++i] && s2[i])
		if (ft_strncmp_ignrcase(s1, s2, i + 1))
			return (0);
	return (1);
}
