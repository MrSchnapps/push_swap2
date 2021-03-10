/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:37:04 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/10 19:41:54 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		free_str(char **str, int ret)
{
	if (str)
	{
		if (*str)
			free(str);
		*str = NULL;
	}
	return (ret);
}

int		ft_free(t_swap *s1, t_swap *s2, int code)
{
	if (s1->stack)
	{
		free(s1->stack);
		s1->stack = NULL;
	}
	if (s2->stack)
	{
		free(s2->stack);
		s2->stack = NULL;
	}
	if (s1->part->t_i)
		free(s1->part->t_i);
	if (s2->part->t_i)
		free(s2->part->t_i);
	if (s1->part)
		free(s1->part);
	if (s2->part)
		free(s2->part);
	exit(code);
	return (code);
}

int		ft_error(int code)
{
	ft_putstr_fd("Error\n", 2);
	exit(code);
	return (code);
}
