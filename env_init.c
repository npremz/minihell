/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:58:51 by npremont          #+#    #+#             */
/*   Updated: 2024/02/07 23:25:58 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_list_swap(t_list *list)
{
	void	*data;

	data = list->content;
	list->content = list->next->content;
	list->next->content = data;
}

void	ft_list_sort(t_list *begin_list, int (*c)())
{
	t_list		*a;
	t_list		*b;
	t_globvar	*var;
	t_globvar	*next_var;

	a = begin_list;
	while (a != NULL)
	{
		b = begin_list;
		while (b->next != NULL)
		{
			var = b->content;
			next_var = b->next->content;
			if ((*c)(var->name, next_var->name, ft_strlen(var->name)) > 0)
				ft_list_swap(b);
			b = b->next;
		}
		a = a->next;
	}
}

void	ft_print_secret(t_list *en)
{
	t_globvar	*var;

	ft_list_sort(en, ft_strncmp);
	while (en)
	{
		var = en->content;
		printf("declare -x %s=\"%s\"\n", var->name, var->value);
		en = en->next;
	}
}

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
