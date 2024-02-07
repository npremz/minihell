/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:47:22 by npremont          #+#    #+#             */
/*   Updated: 2024/02/07 11:51:21 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_list *en)
{
	t_globvar	*var;

	while (en)
	{
		var = en->content;
		if (var->is_secret == 0)
			printf("%s=%s\n", var->name, var->value);
		en = en->next;
	}
	return (EXIT_SUCCESS);
}
