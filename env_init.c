/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:58:51 by npremont          #+#    #+#             */
/*   Updated: 2024/02/08 17:43:24 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_print_secret(t_list *en)
{
	char	**en_tab;
	char	*tmp;
	size_t	i;

	en_tab = ft_en_to_tab(en);
	if (!en_tab)
		return (EXIT_FAILURE);
	i = 0;
	while (en_tab[++i])
	{
		if (ft_strncmp(en_tab[i], en_tab[i - 1], ft_strlen(en_tab[i - 1])) < 0)
		{
			tmp = en_tab[i];
			en_tab[i] = en_tab[i - 1];
			en_tab[i - 1] = tmp;
			i = 0;
		}
	}
	ft_print_export(en_tab);
	ft_free_split(en_tab);
	return (EXIT_SUCCESS);
}

int	ft_get_globvar(char *varline, t_globvar **var)
{
	(*var)->name = ft_get_varname(varline);
	if (!(*var)->name)
		return (0);
	(*var)->value = ft_get_varvalue(varline);
	if (!(*var)->name)
		return (free((*var)->name), 0);
	return (1);
}

void	ft_envinit(t_list **en, char **envp)
{
	size_t		i;
	t_list		*new_node;
	t_globvar	*var;

	i = 0;
	var = NULL;
	new_node = NULL;
	if (!envp)
		exit_error("Error: Initialisation failed.\n", en, var, EXIT_FAILURE);
	while (envp[i])
	{
		var = malloc(sizeof(t_globvar));
		if (!var)
			exit_error("Error: Initialisation failed.\n", en, var, EXIT_FAILURE);
		if (ft_get_globvar(envp[i], &var) == 0)
			exit_error("Error: Initialisation failed.\n", en, var, EXIT_FAILURE);
		new_node = ft_lstnew(var);
		var->is_secret = 0;
		if (!new_node)
			exit_error("Error: Initialisation failed.\n", en, var, EXIT_FAILURE);
		ft_lstadd_back(en, new_node);
		++i;
	}
}
