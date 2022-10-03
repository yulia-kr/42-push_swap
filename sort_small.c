/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:01:28 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/10/02 10:22:51 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_done(t_stack *stack)
{
	int		len;
	t_node	*top;

	top = stack->stack_a;
	len = stack->len_a - 1;
	while (len-- > 0)
	{
		if (top->index > top->next->index)
			return (0);
		top = top->next;
	}
	return (1);
}

void	sort_three_a(t_stack *stack)
{
	int	n;
	int	nnext;
	int	nprev;

	n = stack->stack_a->index;
	nnext = stack->stack_a->next->index;
	nprev = stack->stack_a->prev->index;
	if (nnext > n && nnext > nprev)
		rra(stack, 1);
	else if (n > nnext && n > nprev)
		ra(stack, 1);
	n = stack->stack_a->index;
	nnext = stack->stack_a->next->index;
	if (n > nnext)
		sa(stack, 1);
}

void	sort_three_b(t_stack *stack)
{
	int	n;
	int	nnext;
	int	nprev;
	int	len;

	n = stack->stack_b->index;
	nnext = stack->stack_b->next->index;
	nprev = stack->stack_b->prev->index;
	len = stack->len_b;
	if (nnext > n && nnext > nprev)
		rrb(stack, 1);
	else if (n > nnext && n > nprev)
		rb(stack, 1);
	n = stack->stack_b->index;
	nnext = stack->stack_b->next->index;
	if (n > nnext)
		sb(stack, 1);
	while (len-- > 0)
	{
		stack->stack_b->check = -1;
		pa(stack, 1);
		ra(stack, 1);
	}
}

int	stack_min(t_stack *stack)
{
	int		i;
	int		j;
	t_node	*tmp;

	tmp = stack->stack_a;
	i = 0;
	while (++i)
	{
		if (tmp->index == stack->min)
			break ;
		tmp = tmp->next;
	}
	tmp = stack->stack_a;
	j = 0;
	while (++j)
	{
		if (tmp->index == stack->min)
			break ;
		tmp = tmp->prev;
	}
	if (j >= i)
		return (1);
	return (0);
}

void	sort_five(t_stack *stack)
{
	while (stack->len_a > 3)
	{
		num_value_a(stack);
		if (stack->stack_a->index == stack->min)
		{
			pb(stack, 1);
			continue ;
		}
		if (stack_min(stack))
			ra(stack, 1);
		else
			rra(stack, 1);
	}
	sort_three_a(stack);
	pa(stack, 1);
	pa(stack, 1);
}
