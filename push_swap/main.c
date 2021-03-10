/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:27:22 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/09 16:40:07 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.hpp"

/*
** First parsing is an argument isn't a number return a error code (NAN) else return 0
*/



int main(int argc, char **argv)
{
	t_swap	a;
	t_swap	b;
	int64_t	err;

	if (argc < 2)
		return (0);
	if (init(&a, &b, argc))
		return (ft_free(&a, &b, MERR));
	if ((err = parse_args(argv)))
		return (err);
	if ((err = allocate_stack(&a, &b, argv, argc)))
		return (err);
	if ((err = ft_find(&a, &b)))
		return (ft_free(&a, &b, err));
	
	/*printf("\n===== Stack fin prog =====\n");
	print_stack(&a);
	print_stack(&b);*/
	//free final
	ft_free(&a, &b, 0);
	return (0);
}