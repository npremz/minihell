/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:49:05 by npremont          #+#    #+#             */
/*   Updated: 2024/02/07 22:05:59 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_list		*en;
	char		*line;
	char		**test_cd;

	(void)argc;
	(void)argv;
	(void)line;
	ft_envinit(&en, envp);
	while (1)
	{
		line = readline ("minishell> ");
		add_history(line);
		if (ft_strncmp(line, "exit", 4) == 0)
		{
			free(line);
			break ;
		}
		if (ft_strncmp(line, "env", 3) == 0)
			ft_env(en);
		if (ft_strncmp(line, "pwd", 3) == 0)
			ft_pwd();
		if (ft_strncmp(line, "cd", 2) == 0)
		{
			test_cd = ft_split(line, ' ');
			ft_cd(test_cd, &en);
			ft_free_split(test_cd);
		}
		if (ft_strncmp(line, "export", 6) == 0)
		{
			test_cd = ft_split(line, ' ');
			ft_export(test_cd, &en);
			ft_free_split(test_cd);
		}
		if (ft_strncmp(line, "unset", 5) == 0)
		{
			test_cd = ft_split(line, ' ');
			ft_unset(test_cd, &en);
			ft_free_split(test_cd);
		}
	}
	ft_envclear(&en, free_globvar);
	return (0);
}
