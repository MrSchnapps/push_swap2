/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:19:52 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/10 19:56:18 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	allocate_stack(t_swap *a, t_swap *b, char **argv, int argc)
{
	size_t i;
	size_t j;

	j = 0;
	if (!(a->stack = (int64_t *)malloc(sizeof(int64_t) * (argc - 1))))
		return (ft_error(MERR));
	if (!(b->stack = (int64_t *)malloc(sizeof(int64_t) * (argc - 1))))
		return (ft_error(ft_free(a, b, MERR)));
	while (--argc > 0)
	{
		a->stack[j] = (int64_t)ft_atoil(argv[argc]);
		if (a->stack[j] > INT32_MAX || a->stack[j] < INT32_MIN)
			return (ft_error(ft_free(a, b, OFERR)));
		a->len++;
		j++;
	}
	i = -1;
	while (++i < a->len - 1)
	{
		j = i;
		while (++j < a->len)
			if (a->stack[i] == a->stack[j])
				return (ft_error(ft_free(a, b, DERR)));
	}
	return (0);
}

int	parse_args(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] == ' ' || argv[i][j] == '\t' || argv[i][j] == '\n'
				|| argv[i][j] == '\r' || argv[i][j] == '\v'
				|| argv[i][j] == '\f')
			j++;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j += 1;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (ft_error(NAN));
			j++;
		}
		i++;
	}
	return (0);
}

int	init(t_swap *sa, t_swap *sb, int argc)
{
	sa->size = argc - 1;
	sb->size = argc - 1;
	sa->stack = NULL;
	sb->stack = NULL;
	sa->len = 0;
	sb->len = 0;
	sa->part = NULL;
	sb->part = NULL;
	sa->part = (t_part *)malloc(sizeof(t_part));
	if (!sa->part)
		return (ft_error(MERR));
	sb->part = (t_part *)malloc(sizeof(t_part));
	if (!sb->part)
		return (ft_error(MERR));
	sa->part->t_i = NULL;
	sb->part->t_i = NULL;
	sa->part->len = 0;
	sb->part->len = 0;
	return (0);
}
