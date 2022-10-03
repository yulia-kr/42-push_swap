/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:47:38 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/10/01 10:31:26 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->stack_b->next;
	stack->stack_b->prev->next = stack->stack_b->next;
	stack->stack_b->next->prev = stack->stack_b->prev;
	if (stack->stack_a)
	{
		stack->stack_b->prev = stack->stack_a->prev;
		stack->stack_b->next = stack->stack_a;
		stack->stack_a->prev->next = stack->stack_b;
		stack->stack_a->prev = stack->stack_b;
		stack->stack_a = stack->stack_b;
	}
	else
	{
		stack->stack_a = stack->stack_b;
		stack->stack_a->next = stack->stack_a;
		stack->stack_a->prev = stack->stack_a;
	}
	stack->stack_b = tmp;
}

void	pa(t_stack *stack, int print)
{
	if (stack->len_b == 0)
		return ;
	push_a(stack);
	if (stack->len_b == 1)
		stack->stack_b = NULL;
	stack->len_b--;
	stack->len_a++;
	if (print)
		write(1, "pa\n", 3);
}

void	push_b(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->stack_a->next;
	stack->stack_a->prev->next = stack->stack_a->next;
	stack->stack_a->next->prev = stack->stack_a->prev;
	if (stack->stack_b)
	{
		stack->stack_a->prev = stack->stack_b->prev;
		stack->stack_a->next = stack->stack_b;
		stack->stack_b->prev->next = stack->stack_a;
		stack->stack_b->prev = stack->stack_a;
		stack->stack_b = stack->stack_a;
	}
	else
	{
		stack->stack_b = stack->stack_a;
		stack->stack_a->next = stack->stack_b;
		stack->stack_a->prev = stack->stack_b;
	}
	stack->stack_a = tmp;
}

void	pb(t_stack *stack, int print)
{
	if (stack->len_a == 0)
		return ;
	push_b(stack);
	if (stack->len_a == 1)
		stack->stack_a = NULL;
	stack->len_b++;
	stack->len_a--;
	if (print)
		write(1, "pb\n", 3);
}
