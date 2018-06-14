/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:27:28 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/08 07:18:08 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(void)
{
	/*char	test1[3] = "abc";
	char	test2[3] = "abc";
	printf("%u\n", ft_strlcat(test1, "defgh", 0));
	printf("%u\n", strlcat(test2, "defgh", 0));
	printf("%s | %s\n", test1, test2);*/
	/*printf("%d\n", ft_strncmp("\200", "\0", 1));
	printf("%d\n", strncmp("\200", "\0", 1));*/
	printf("%s\n", ft_itoa(-623));
	printf("%s\n", ft_itoa(156));
	printf("%s\n", ft_itoa(-0));
	return (0);
}
