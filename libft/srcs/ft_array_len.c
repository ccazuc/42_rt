/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <ccazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:22:36 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/24 10:26:40 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		++i;
	return (i);
}
