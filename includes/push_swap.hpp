/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:27:56 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/09 16:41:35 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# define NAN 3
# define MERR 4
# define DERR 5
# define INDERR 6
# define OFERR 7
# define ERR 2

typedef struct	s_part
{
	size_t		*t_i;
	int			len;
}				t_part;

typedef struct	s_swap 
{
	int64_t*	stack;
	size_t		size;
	size_t		len;
	t_part		*part;
}				t_swap;

/*
** Free - Errors
*/

int		ft_free(t_swap *a, t_swap *b, int code);
int		ft_error(int code);
int		free_str(char **str, int ret);

/*
** Lib
*/

int64_t	ft_atoil(const char *nptr);
int		ft_strlen(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_strcmp(char *s1, char *s2);
void	swap(int64_t *n1, int64_t *n2);

/*
** Utils
*/

void	print_stack(t_swap *s);
void	print_part(t_swap *s);
int		getMedian(int64_t *stack, int64_t start, int64_t end, int64_t *med);
int		add_index(t_part **s, size_t index);

/*
** Parsing
*/

int		allocate_stack(t_swap *a, t_swap *b, char **argv, int argc);
int		parse_args(char **argv);
int		init(t_swap *sa, t_swap *sb, int argc);

/*
** Operations
*/

void	sa(t_swap *a, t_swap *b);
void	sb(t_swap *a, t_swap *b);
void	ss(t_swap *a, t_swap *b);
void	pa(t_swap *a, t_swap *b);
void	pb(t_swap *a, t_swap *b);
void	ra(t_swap *a, t_swap *b);
void	rb(t_swap *a, t_swap *b);
void	rr(t_swap *a, t_swap *b);
void	rra(t_swap *a, t_swap *b);
void	rrb(t_swap *a, t_swap *b);
void	rrr(t_swap *a, t_swap *b);
void	rrr(t_swap *a, t_swap *b);

/*
** List
*/

void	lst_pop(t_part **lst);
t_part	*lst_last(t_part *lst);
t_part	*lst_new_prt(int index);
int		lst_add_prt(t_part **prt, int index);

/*
** Algo
*/

int		ft_find(t_swap *a, t_swap *b);
int		check_sorted(t_swap *s);
void	sort_three(t_swap *a, t_swap *b);
void	sort_three_a(t_swap *a, t_swap *b);
void	sort_three_b(t_swap *a, t_swap *b);
#endif