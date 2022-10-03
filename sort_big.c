/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:23:00 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/10/02 10:20:54 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_minb(t_stack *stack)
{
	int	min;

	min = stack->stack_a->prev->index + 1;
	if (stack->stack_b->index == min)
	{
		pa(stack, 1);
		push_down(stack);
		return (1);
	}
	else if (stack->stack_a->index == min)
		push_down(stack);
	else if (stack->stack_a->next->index == min)
	{
		sa(stack, 1);
		push_down(stack);
	}
	return (0);
}

void	move_minb(t_stack *stack)
{
	int	len;

	num_value_b(stack);
	len = stack->len_b;
	while (len-- > 0)
	{
		if (search_minb(stack))
			continue ;
		if (stack->stack_b->index > stack->med)
		{
			stack->stack_b->check++;
			pa(stack, 1);
		}
		else
		{
			stack->stack_b->check++;
			rb(stack, 1);
		}
	}
}

void	move_mina(t_stack *stack)
{
	int	check;
	int	min;

	check = stack->stack_a->check;
	while (stack->stack_a->check == check && check != -1)
	{
		min = stack->stack_a->prev->index + 1;
		if (stack->len_b > 1)
			search_mina(stack);
		if (stack->stack_a->index == min)
			push_down(stack);
		else
			pb(stack, 1);
	}
}

void	push_down(t_stack *stack)
{
	stack->stack_a->check = -1;
	ra(stack, 1);
}

void	search_mina(t_stack *stack)
{
	int	min;

	min = stack->stack_a->prev->index + 1;
	if (stack->stack_b->index == min)
	{
		pa(stack, 1);
		push_down(stack);
	}
	else if (stack->stack_b->next->index == min)
	{
		sb(stack, 1);
		pa(stack, 1);
		push_down(stack);
	}
	else if (stack->stack_b->prev->index == min)
	{
		rrb(stack, 1);
		pa(stack, 1);
		push_down(stack);
	}
	else if (stack->stack_a->next->index == min)
	{
		sa(stack, 1);
		push_down(stack);
	}
}
