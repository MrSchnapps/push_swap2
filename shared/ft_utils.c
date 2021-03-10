/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:40:18 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/09 16:43:07 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.hpp"

int64_t		ft_atoil(const char *nptr)
{
	int					sign;
	int64_t				nb;

	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	nb = 0;
	while (*nptr >= 48 && *nptr <= 57)
	{
		nb = (nb * 10) + *nptr - '0';
		nptr++;
	}
	return ((int64_t)(nb * sign));
}

void	swap(int64_t *n1, int64_t *n2)
{
	int64_t swp;

	swp = *n1;
	*n1 = *n2;
	*n2 = swp;
}

/*
** Return 1 if the list is sorted or 0 if not
*/

int		check_sorted(t_swap *s)
{
	size_t i;

	i = s->len - 1;
	if (s->len != s->size)
		return (0);
	while (i > 0)
	{
		if (s->stack[i] > s->stack[i - 1])
			return (0);
		i--;	
	}
	return (1);
}