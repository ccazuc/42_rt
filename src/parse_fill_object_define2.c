/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill_object_define2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:23:40 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/14 15:14:42 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_object_refraction_define(t_object *object,
t_define *define, int *i)
{
	if (define->nb_value != 1)
		ft_exit("Error, invalid file. Define has too much arguments for refr."
		, EXIT_FAILURE);
	object->refraction = define->x / 100.;
	if (object->refraction < 1. || object->refraction > 2.)
		ft_exit("Error, invalid file. Refr's param's value is invalid."
		, EXIT_FAILURE);
	object->has_parsed_refraction = 1;
	*i += 1;
}
