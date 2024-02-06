/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:58:51 by npremont          #+#    #+#             */
/*   Updated: 2024/02/06 12:10:01 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_globvar(char *varline, t_globvar **var)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (varline[i] != '=')
		++i;
	(*var)->name = malloc((i + 1) * sizeof(char));
	if (!((*var)->name))
		return (0);
	i = -1;
	while (varline[++i] != '=')
		((*var)->name)[i] = varline[i];
	(*var)->name[i++] = '\0';
	j = i;
	while (varline[j] != '\0')
		j++;
	(*var)->value = malloc((j - i + 1) * sizeof(char));
	if (!((*var)->value))
		return (free((*var)->name), 0);
	j = i - 1;
	while (varline[++j] != '\0')
		(*var)->value[j - i] = varline[j];
	(*var)->value[j - i] = '\0';
	(*var)->is_secret = 0;
	return (1);
}

void	ft_envinit(t_list **en, char **envp)
{
	size_t		i;
	t_list		*new_node;
	t_globvar	*var;

	i = 0;
	var = NULL;
	if (!envp)
		exit_error("Error: Initialisation failed.", en, var, EXIT_FAILURE);
	while (envp[i])
	{
		var = malloc(sizeof(t_globvar));
		if (!var)
			exit_error("Error: Initialisation failed.", en, var, EXIT_FAILURE);
		if (ft_get_globvar(envp[i], &var) == 0)
			exit_error("Error: Initialisation failed.", en, var, EXIT_FAILURE);
		new_node = ft_lstnew(var);
		if (!new_node)
			exit_error("Error: Initialisation failed.", en, var, EXIT_FAILURE);
		ft_lstadd_back(en, new_node);
		++i;
	}
}
