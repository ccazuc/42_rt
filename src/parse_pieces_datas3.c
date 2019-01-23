/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pieces_datas3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:35:02 by kehuang           #+#    #+#             */
/*   Updated: 2019/01/23 16:35:17 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "rt.h"

void	parse_object_texu(t_env *env, t_object *object
		, char **datas, int *start)
{
	struct stat	st;

	(void)env;
	if (object->has_parsed_texu)
		ft_exit("Error, invalid file. Texture duplicate for an object."
				, EXIT_FAILURE);
	if (!datas[*start + 1])
		ft_exit("Error, invalid file. Not enough parameters for texture."
				, EXIT_FAILURE);
	if (ft_strlen(datas[*start + 1]) < 4
			|| ft_strrchr(datas[*start + 1], '.') == NULL
			|| ft_strcmp(ft_strrchr(datas[*start + 1], '.'), ".bmp") != 0)
		ft_exit("Error, invalid file.", EXIT_FAILURE);
	if (stat(datas[*start + 1], &st) == -1)
		ft_exit("Error, invalid file.", EXIT_FAILURE);
	if ((st.st_mode & S_IRUSR) == 0)
		ft_exit("Error, can't read file.", EXIT_FAILURE);
	if ((object->texu = load_bmp(datas[*start + 1])) == NULL)
		ft_exit("Error, corrupted .bmp file.", EXIT_FAILURE);
	*start += 1;
	object->has_parsed_texu = 1;
}
