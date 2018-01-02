/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:17:41 by ccazuc            #+#    #+#             */
/*   Updated: 2018/01/02 12:57:59 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static char		*build_line(t_gnl *env)
{
	int		i;

	i = -1;
	env->curr_line = 0;
	while (env->datas[++i])
		if (env->datas[i] == '\n')
		{
			++env->curr_line;
			if (env->curr_line == env->line)
				env->start = i;
			else if (env->curr_line == env->line + 1)
			{
				env->end = i;
				break ;
			}
		}
	if (env->curr_line <= env->line)
		return (NULL);
	env->buff_pos = i + 1;
	if (env->end == -1)
		return (ft_strsub_start(env->datas, env->start));
	if (env->start == -1)
		return (ft_strsub(env->datas, 0, env->end));
	return (ft_strsub(env->datas, env->start + 1, env->end - env->start - 1));
}

static int		add_datas(char *datas, t_gnl *env)
{
	int		i;

	if (!(env->datas = ft_strjoin_free1(env->datas, datas)))
		return (-1);
	i = -1;
	env->curr_line = -1;
	while (env->datas[++i])
		if (env->datas[i] == '\n')
		{
			++env->curr_line;
			if (env->curr_line == env->line)
				return (1);
		}
	return (0);
}

static char		*get_n_line(t_gnl *env)
{
	int		datas_read;
	char	buffer[BUFF_SIZE + 1];
	int		returned_value;
	char	*tmp;

	env->curr_line = 0;
	if (env->buff_pos < env->buff_len)
		if ((tmp = build_line(env)))
			return (tmp);
	while ((datas_read = read(env->fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[datas_read] = '\0';
		env->buff_len += datas_read;
		returned_value = add_datas(buffer, env);
		if (returned_value == -1)
			return (NULL);
		if (returned_value == 1)
			return (build_line(env));
	}
	return (NULL);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl		*env;

	if (!env)
	{
		if (!(env = malloc(sizeof(*env))))
			return (-1);
		if (!(env->datas = malloc(1)))
			return (-1);
		env->datas[0] = '\0';
		env->buff_len = 0;
		env->buff_pos = 0;
		env->line = -1;
	}
	++env->line;
	env->fd = fd;
	env->start = -1;
	env->end = -1;
	if (!(*line = get_n_line(env)))
		return (-1);
	return (1);
}
