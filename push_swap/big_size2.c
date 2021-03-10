/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_size2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:15:59 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/10 14:13:31 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.hpp"

size_t	find_max(t_swap *s)
{
	int64_t test;
	size_t	i;
	size_t	ret;

	test = s->stack[0];
	i = 0;
	ret = 0;
	while (i < s->len)
	{
		if (test < s->stack[i])
		{
			test = s->stack[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}