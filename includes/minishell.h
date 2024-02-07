/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:52:04 by npremont          #+#    #+#             */
/*   Updated: 2024/02/07 23:21:24 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

/* STRUCTURES */

typedef struct s_globvar
{
	char	*name;
	char	*value;
	int		is_secret;
}	t_globvar;

/* BUILTINS */

int		ft_cd(char **args, t_list **en);
int		ft_export(char **args, t_list **en);
int		ft_export_var(int type, t_list *en, t_globvar *var);
int		ft_env(t_list *en);
int		ft_pwd(void);
int		ft_unset(char **args, t_list **en);

void	ft_envinit(t_list **en, char **envp);
int		ft_get_globvar(char *varline, t_globvar **var);
void	ft_print_secret(t_list *en);

/* FREE UTILS */

void	ft_envclear(t_list **lst, void (*del)(t_globvar *));

/* ERROR HANDLING */

void	exit_error(char *str, t_list **en, t_globvar *var, int code);
void	print_error(char *str);
void	free_globvar(t_globvar *ptr);

#endif
