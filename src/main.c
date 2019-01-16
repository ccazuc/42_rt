/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:34:08 by ccazuc            #+#    #+#             */
/*   Updated: 2019/01/16 12:48:10 by kehuang          ###   ########.fr       */
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

static void	env_run(t_env **env, char **argv)
{
	int	i;

	i = -1;
	while (env[++i])
		parse(env[i], argv[i + 1]);
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
		env[i - 1]->file_name = argv[i];
	}
	srand(time(NULL));
	env_run(env, argv);
	return (0);
}
