/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:01:58 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/10 19:49:58 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_in_steps(t_chunk *chunk, int step, int64_t nb)
{
	int64_t i;

	if (step == 0)
		i = 0;
	else
		i = chunk->steps[step - 1];
	while (i < chunk->steps[step])
	{
		if (nb == chunk->values[i])
			return (1);
		i++;
	}
	return (0);
}

int64_t	find_nb(t_swap *s, t_chunk *chunk, int step)
{
	int64_t i;
	int64_t top;
	int64_t bot;

	i = (int64_t)s->len + 1;
	top = 0;
	bot = 0;
	while (--i > 0)
		if (find_in_steps(chunk, step, s->stack[i - 1]))
		{
			top = (int64_t)s->len - i;
			break ;
		}
	i = -1;
	while (++i < (int64_t)s->len)
		if (find_in_steps(chunk, step, s->stack[i]))
		{
			bot = i + 1;
			break ;
		}
	if (top <= bot)
		return (top);
	return (bot *= -1);
}

void	first_split(t_swap *a, t_swap *b, t_chunk *chunks, int64_t size)
{
	int64_t i;
	int64_t	rot;

	i = -1;
	while (++i < size)
	{
		while ((int64_t)b->len < chunks->steps[i])
		{
			rot = find_nb(a, chunks, i);
			if (rot > 0)
				while (rot-- > 0)
					ra(a, b);
			else
				while (rot++ < 0)
					rra(a, b);
			pusher_b(a, b);
		}
	}
}

t_chunk	*add_step(t_swap *a, int64_t size)
{
	int64_t step;
	t_chunk *chunks;
	int64_t	i;

	i = 0;
	step = a->size / size;
	chunks = (t_chunk *)malloc(sizeof(t_chunk));
	if (!chunks)
		ft_error(MERR);
	chunks->steps = (int64_t *)malloc(size * sizeof(int64_t));
	if (!chunks->steps)
		ft_error(MERR);
	chunks->steps[0] = step;
	while (++i < size - 1)
		chunks->steps[i] = chunks->steps[i - 1] + step;
	chunks->steps[size - 1] = a->size;
	chunks->values = (int64_t *)malloc(a->size * sizeof(int64_t));
	if (!chunks->values)
		ft_error(MERR);
	step = -1;
	while (++step < (int64_t)a->size)
		chunks->values[step] = a->stack[step];
	sort_tab(chunks->values, a->size);
	return (chunks);
}

void	big_size(t_swap *a, t_swap *b)
{
	int64_t size;
	t_chunk *chunks;

	size = 5;
	if (a->size > 399)
		size = 11;
	chunks = add_step(a, size);
	first_split(a, b, chunks, size);
	while (!check_sorted(a))
		recover_a(a, b);
	free(chunks->values);
	free(chunks->steps);
	free(chunks);
}
