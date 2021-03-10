/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:27:56 by judecuyp          #+#    #+#             */
/*   Updated: 2021/03/10 20:45:21 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# define NAN 3
# define MERR 4
# define DERR 5
# define INDERR 6
# define OFERR 7
# define ERR 2

typedef struct	s_chunk
{
	int64_t	*steps;
	int64_t	*values;
}				t_chunk;

typedef struct	s_part
{
	size_t	*t_i;
	int		len;
}				t_part;

typedef struct	s_swap
{
	int64_t	*stack;
	size_t	size;
	size_t	len;
	t_part	*part;
}				t_swap;

/*
** Free - Errors
*/

int				ft_free(t_swap *a, t_swap *b, int code);
int				ft_error(int code);
int				free_str(char **str, int ret);

/*
** Lib
*/

int64_t			ft_atoil(const char *nptr);
int				ft_strlen(char *str);
void			ft_putstr_fd(char *str, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
int				ft_strcmp(char *s1, char *s2);
void			swap(int64_t *n1, int64_t *n2);

/*
** Utils
*/

void			print_stack(t_swap *s);
int				get_median(int64_t *stack,
int64_t start, int64_t end, int64_t *med);
int				add_index(t_part **s, size_t index);
size_t			find_max(t_swap *s);
int				is_min(int64_t nb, t_swap *s);
size_t			find_min(int64_t nb, t_swap *s);

/*
** Parsing
*/

int				allocate_stack(t_swap *a, t_swap *b, char **argv, int argc);
int				parse_args(char **argv);
int				init(t_swap *sa, t_swap *sb, int argc);

/*
** Operations
*/

void			sa(t_swap *a, t_swap *b);
void			sb(t_swap *a, t_swap *b);
void			ss(t_swap *a, t_swap *b);
void			pa(t_swap *a, t_swap *b);
void			pb(t_swap *a, t_swap *b);
void			ra(t_swap *a, t_swap *b);
void			rb(t_swap *a, t_swap *b);
void			rr(t_swap *a, t_swap *b);
void			rra(t_swap *a, t_swap *b);
void			rrb(t_swap *a, t_swap *b);
void			rrr(t_swap *a, t_swap *b);
void			rrr(t_swap *a, t_swap *b);

/*
** Algo
*/

int				ft_find(t_swap *a, t_swap *b);
int				check_sorted(t_swap *s);
void			sort_three(t_swap *a, t_swap *b);
void			sort_three_a(t_swap *a, t_swap *b);
void			sort_three_b(t_swap *a, t_swap *b);
void			sort_tab(int64_t *tab, int64_t size);

/*
** Big size
*/

void			big_size(t_swap *a, t_swap *b);
void			recover_a(t_swap *a, t_swap *b);
void			pusher_b(t_swap *a, t_swap *b);
#endif
