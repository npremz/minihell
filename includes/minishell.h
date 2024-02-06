/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:52:04 by npremont          #+#    #+#             */
/*   Updated: 2024/02/06 17:17:39 by npremont         ###   ########.fr       */
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

void	ft_envinit(t_list **en, char **envp);
int		ft_get_globvar(char *varline, t_globvar **var);

/* ERROR HANDLING */

void	exit_error(char *str, t_list **en, t_globvar *var, int code);
void	print_error(char *str);
void	free_globvar(void *ptr);

#endif
