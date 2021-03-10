/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:01:58 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/10 14:21:22 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.hpp"

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

void	recover_a(t_swap *a, t_swap *b)
{
	size_t rot;

	rot = find_max(b);
	//sleep(1);
	//printf("\nrottt ===>> |%ld|\n", b->stack[rot]);
	//print_stack(b);
	//sleep(2);
	if (rot < b->len / 2)
	{
		rot++;
		while (rot-- > 0)
			rrb(a, b);
	}
	else
		while (rot++ < b->len - 1)
			rb(a, b);
	//print_stack(b);
	//sleep(3);
	pa(a, b);
	//print_stack(a);
	//sleep(2);
}

void	first_split(t_swap *a, t_swap *b, t_chunk *chunks)
{
	int64_t i;
	int64_t	rot;

	i = -1;
	while (++i < 5)
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
			pb(a, b);
			//pusher_b(a, b);
		}
	}
	//recover_a(a, b);
	//print_stack(b);
}

t_chunk	*add_step(t_swap *a)
{
	int64_t step;
	t_chunk *chunks;

	step = a->size / 5;
	chunks = (t_chunk *)malloc(sizeof(t_chunk));
	if(!chunks)
		ft_error(MERR);
	chunks->steps = (int64_t *)malloc(5 * sizeof(int64_t));
	if (!chunks->steps)
		ft_error(MERR);
	chunks->steps[0] = step;
	chunks->steps[1] = chunks->steps[0] + step;
	chunks->steps[2] = chunks->steps[1] + step;
	chunks->steps[3] = chunks->steps[2] + step;
	chunks->steps[4] = a->size;
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
	t_chunk *chunks;

	chunks = add_step(a);
	first_split(a, b, chunks);
	while (!check_sorted(a))
		recover_a(a, b);
	free(chunks->values);
	free(chunks->steps);
	free(chunks);
}