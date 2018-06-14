/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:38:45 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/14 09:38:55 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static char	*get_file_name(void)
{
	time_t		now;
	struct tm	tm_now;
	char		file_name[128];

	now = time(NULL);
	localtime_r(&now, &tm_now);
	strftime(file_name, sizeof(file_name),
	"screenshots/render_%Y_%m_%d_%H_%M_%S", &tm_now);
	return (ft_strdup(file_name));
}

void		save_image(t_env *env)
{
	int		fd;
	char	*file_name;

	file_name = get_file_name();
	printf("%s\n", file_name);
	fd = open(file_name, O_CREAT | O_RDWR, S_IRWXO);
	printf("fd: %d\n", fd);
	free(file_name);
	(void)env;
}
