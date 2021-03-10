/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:18:56 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/10 20:16:24 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	select_move(t_swap *a, t_swap *b, char *line)
{
	if (!ft_strcmp(line, "sa"))
		sa(a, b);
	else if (!ft_strcmp(line, "sb"))
		sb(a, b);
	else if (!ft_strcmp(line, "ss"))
		ss(a, b);
	else if (!ft_strcmp(line, "pa"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb"))
		pb(a, b);
	else if (!ft_strcmp(line, "ra"))
		ra(a, b);
	else if (!ft_strcmp(line, "rb"))
		rb(a, b);
	else if (!ft_strcmp(line, "rr"))
		rr(a, b);
	else if (!ft_strcmp(line, "rra"))
		rra(a, b);
	else if (!ft_strcmp(line, "rrb"))
		rrb(a, b);
	else if (!ft_strcmp(line, "rrr"))
		rrr(a, b);
	else
		return (ft_error(ERR));
	return (0);
}

int	resolve(t_swap *a, t_swap *b)
{
	int		solved;
	char	*line;
	int		ret;

	solved = 0;
	ret = 1;
	while (ret > 0 && !solved)
	{
		ret = get_next_line(0, &line);
		if (ret <= 0)
			return (ft_error(MERR));
		if (select_move(a, b, line))
			return (free_str(&line, ERR));
		if (check_sorted(a))
			solved = 1;
	}
	if (solved)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_swap	a;
	t_swap	b;
	int64_t	err;

	if (argc < 2)
		return (0);
	if (init(&a, &b, argc))
		return (ft_free(&a, &b, MERR));
	err = parse_args(argv);
	if (err)
		return (err);
	err = allocate_stack(&a, &b, argv, argc);
	if (err)
		return (err);
	if (check_sorted(&a))
		return (ft_free(&a, &b, 0));
	err = resolve(&a, &b);
	if (err)
		return (ft_free(&a, &b, (int)err));
	ft_free(&a, &b, 0);
	return (0);
}
