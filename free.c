/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:08:18 by npremont          #+#    #+#             */
/*   Updated: 2024/02/06 12:08:15 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_globvar(void *ptr)
{
	if (((t_globvar *)ptr)->name)
		ft_free((void **)&(((t_globvar *)ptr)->name));
	if (((t_globvar *)ptr)->value)
		ft_free((void **)&(((t_globvar *)ptr)->value));
	if (((t_globvar *)ptr))
		ft_free(&ptr);
}
