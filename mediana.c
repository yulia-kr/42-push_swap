/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediana.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:18:31 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/10/02 11:34:06 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	num_value_a(t_stack *stack)
{
	int	len;
	int	min;
	int max;
	
	if (stack->len_a == 0)
		return;
	len = stack->len_a;
	min = stack->stack_a->index;
	max = stack->stack_a->index;
	while (len-- > 0)
	{
		if (min > stack->stack_a->index)
			min = stack->stack_a->index;
		if (max < stack->stack_a->index)
			max = stack->stack_a->index;
		stack->stack_a = stack->stack_a->next;
	}
	stack->min = min;
	stack->max = max;
	stack->med = (min + max) / 2;
}

void	num_value_b(t_stack *stack)
{
	int	len;
	int	min;
	int max;

	if (stack->len_b == 0)
		return;
	len = stack->len_b;
	min = stack->stack_b->index;
	max = stack->stack_b->index;
	while (len-- > 0)
	{
		if(min > stack->stack_b->index)
			min = stack->stack_b->index;
		if(max < stack->stack_b->index)
			max = stack->stack_b->index;
		stack->stack_b = stack->stack_b->next;
	}
	stack->max = max;
	stack->med = (min + max) / 2;
}

void	put_bottom(t_stack *stack)
{
	while (stack->stack_b->prev->check == -1)
		rrb(stack, 1);
	while (stack->stack_b->check == -1)
	{
		pa(stack, 1);
		ra(stack, 1);
	}
}

void	med_division_first(t_stack *stack)
{
	int	len;

	num_value_a(stack);
	len = stack->len_a;
	while (len-- > 0)
	{
		if (stack->stack_a->index <= stack->med)
		{
			pb(stack, 1);
			if (stack->stack_b->index == stack->min)
			{
				stack->stack_b->check = -1;
				rb(stack, 1);
			}
		}
		else
		{
			if (stack->len_b == stack->max - stack->med + 1)
				break ;
			else
				ra(stack, 1);
		}
	}
	put_bottom(stack);
}
