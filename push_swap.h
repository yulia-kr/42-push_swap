/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 09:41:32 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/10/01 11:02:07 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct	s_node
{
	int				num;
	int				index;
	int				check;
	struct s_node 	*next;
	struct s_node	*prev;
}					t_node;

typedef struct	s_stack
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		len_a;
	int		len_b;
	int		min;
	int		max;
	int 	med;
	int		btm_a;
}			t_stack;

char	**get_line(char **av);
void	check_doubles(char **arr);
void	check_num(char **arr);
void	free_ps(char **arr, int print);
void	error(void);

t_stack	*init_stack(char **arr);
t_node	*new_list(int num, int index);
void	lstadd_back(t_node **stack_a, t_node *new);
void	free_stack(t_stack *stack);

void	create_stack(t_stack *stack, int *sort, int *unsort, int len);
void	bubble_sort(t_stack *stack, int *sort, int *unsort, int len);
void	fill_stack(t_stack *stack, char **arr);

void	color(t_stack *stack);
void	print_stacks(t_stack *stack, t_node *tmp_a, t_node *tmp_b);

void	sa(t_stack *stack, int check);
void	sb(t_stack *stack, int check);
void	ss(t_stack *stack, int check);

void	push_a(t_stack *stack);
void	pa(t_stack *stack, int print);
void	push_b(t_stack *stack);
void	pb(t_stack *stack, int print);

void	ra(t_stack *stack, int check);
void	rb(t_stack *stack, int check);
void	rr(t_stack *stack, int check);

void	rra(t_stack *stack, int check);
void	rrb(t_stack *stack, int check);
void	rrr(t_stack *stack, int check);

void	med_division(t_stack *stack);
void	num_value_a(t_stack *stack);
void	num_value_b(t_stack *stack);
void	put_bottom(t_stack *stack);

int		sort_done(t_stack *stack);
void	sort_three_a(t_stack *stack);
void	sort_three_b(t_stack *stack);
void	sort_five(t_stack *stack);
int		stack_min(t_stack *stack);

void	check_stack_b(t_stack *stack, int check);
void	push_a_to_b(t_stack *stack, int check, int min, int len);
void	check_stack_b_second(t_stack *stack, int check);
void	push_b_to_a(t_stack *stack);
void	sort_index_b(t_stack *stack);

int		search_minb(t_stack *stack);
void	move_minb(t_stack *stack);
void	move_mina(t_stack *stack);
void	push_down(t_stack *stack);
void	search_mina(t_stack *stack);

t_stack	*parsing(char **av);
void	sorting(t_stack *stack);

#endif
