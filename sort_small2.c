/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:59:52 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/10/02 10:56:48 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_index_b(t_stack *stack)
{
	int	i;
	int	inext;
	int	iprev;

	if (stack->len_b == 0)
		return ;
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

void	check_stack_b(t_stack *stack, int check)
{
	sort_index_b(stack);
	if (stack->stack_a->index > stack->stack_a->next->index && \
		stack->stack_a->check == stack->stack_a->next->check)
		sa(stack, 1);
	while (stack->len_b != 0)
	{
		if (stack->stack_a->index > stack->stack_b->index || \
			stack->stack_a->check != check)
		{
			pa(stack, 1);
			push_down(stack);
		}
		else
			push_down(stack);
	}
	while (stack->stack_a->check == check && check != -1)
		push_down(stack);
}

void	push_a_to_b(t_stack *stack, int check, int min, int len)
{
	t_node	*tmp;

	min = stack->stack_a->prev->index + 1;
	check = stack->stack_a->check;
	tmp = stack->stack_a;
	while (tmp->check == check && check != -1)
	{
		tmp = tmp->next;
		len++;
	}
	if (len <= 5)
	{
		while (len > 2)
		{
			if (stack->stack_a->index == min)
			{
				push_down(stack);
				min++;
			}
			else
				pb(stack, 1);
			len--;
		}
		check_stack_b(stack, check);
	}
}

void	check_stack_b_second(t_stack *stack, int check)
{
	sort_index_b(stack);
	if (stack->stack_a->index > stack->stack_a->next->index && \
		stack->stack_a->check == stack->stack_a->next->check)
		sa(stack, 1);
	while (stack->len_b != 0)
	{
		if (stack->stack_a->index > stack->stack_b->index || \
			stack->stack_a->check == -1)
		{
			pa(stack, 1);
			push_down(stack);
		}
		else
			push_down(stack);
	}
	while (stack->stack_a->check == check && check != -1 && \
			stack->stack_a->index +1 == stack->stack_a->prev->index)
		push_down(stack);
}

void	push_b_to_a(t_stack *stack)
{
	int		check;
	int		min;
	int		len;

	len = stack->len_b;
	min = stack->stack_a->prev->index + 1;
	check = stack->stack_a->check;
	while (len > 3)
	{
		if (stack->stack_b->index == min)
		{
			pa(stack, 1);
			push_down(stack);
			min++;
		}
		else
			pa(stack, 1);
		len--;
	}
	check_stack_b_second(stack, check);
}
