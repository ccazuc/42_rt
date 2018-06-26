/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:34:08 by ccazuc            #+#    #+#             */
/*   Updated: 2018/06/22 10:53:08 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	init_mlx(t_env **env)
{
	void	*mlx_ptr;
	int		i;

	if (!(mlx_ptr = mlx_init()))
		ft_exit("Error, failed to init mlx connection.", EXIT_FAILURE);
	i = -1;
	while (env[++i])
		env[i]->mlx_ptr = mlx_ptr;
}

static void	env_run(t_env **env, int argc, char **argv)
{
	int	i;

	i = -1;
	while (env[++i])
		parse(env[i], argc, argv[i + 1]);
	i = -1;
	init_mlx(env);
	while (env[++i])
		init_window(env[i]);
	i = -1;
	while (env[++i])
		render(env, i, 1);
	mlx_loop(env[0]->mlx_ptr);
}

int			main(int argc, char **argv)
{
	t_env	**env;
	int		i;

	if (argc == 1)
		ft_exit("Error, no map specified.", EXIT_FAILURE);
	if (!(env = malloc(argc * sizeof(*env))))
		ft_exit("Error, out of memory.", EXIT_FAILURE);
	env[argc - 1] = NULL;
	i = 0;
	while (++i < argc)
	{
		if (!(env[i - 1] = malloc(sizeof(**env))))
			ft_exit("Error, out of memory.", EXIT_FAILURE);
		init_env(env[i - 1]);
		env[i - 1]->id = i - 1;
		env[i - 1]->env_list = env;
	}
	env_run(env, argc, argv);
	return (0);
}
