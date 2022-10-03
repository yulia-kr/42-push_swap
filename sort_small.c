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
	if(n > nnext)
		sa(stack, 1);
}

void	sort_three_b(t_stack *stack)
{
	int	n;
	int	nnext;
	int	nprev;
	int	len;

	len = stack->len_b;
	n = stack->stack_b->index;
	nnext = stack->stack_b->next->index;
	nprev = stack->stack_b->prev->index;
	if (nnext > n && nnext > nprev)
		rrb(stack, 1);
	else if (n > nnext && n > nprev)
		rb(stack, 1);
	n = stack->stack_b->index;
	nnext = stack->stack_b->next->index;
	if(n > nnext)
		sa(stack, 1);
	while (len-- > 0)
	{
		stack->stack_b->check = -1;
		pa(stack, 1);
		ra(stack, 1);
	}
}

void	sort_b_index(t_stack *stack)
{
	int	i;
	int	inext;
	int	iprev;

	if (stack->len_b == 0)
		return;
	i = stack->stack_b->index;
	inext = stack->stack_b->next->index;
	iprev = stack->stack_b->prev->index;
	if (inext > i && inext > iprev)
		rrb(stack, 1);
	else if (i > inext && i > iprev)
		rb(stack, 1);
	i = stack->stack_b->index;
	inext = stack->stack_b->next->index;
	if (i > inext)
		sb(stack, 1);
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
			break;
		tmp = tmp->prev;
	}
	if (j >= i)
		return(1);
	return(0);
}

