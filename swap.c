/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:46:50 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/10/04 09:16:08 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack, int print)
{
	int	tmp;

	if (stack->len_a > 1)
	{
		tmp = stack->stack_a->num;
		stack->stack_a->num = stack->stack_a->next->num;
		stack->stack_a->next->num = tmp;
		tmp = stack->stack_a->index;
		stack->stack_a->index = stack->stack_a->next->index;
		stack->stack_a->next->index = tmp;
		tmp = stack->stack_a->check;
		stack->stack_a->check = stack->stack_a->next->check;
		stack->stack_a->next->check = tmp;
	}
	else
		return ;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack, int print)
{
	int	tmp;

	if (stack->len_b > 1)
	{
		tmp = stack->stack_b->num;
		stack->stack_b->num = stack->stack_b->next->num;
		stack->stack_b->next->num = tmp;
		tmp = stack->stack_b->index;
		stack->stack_b->index = stack->stack_b->next->index;
		stack->stack_b->next->index = tmp;
		tmp = stack->stack_b->check;
		stack->stack_b->check = stack->stack_b->next->check;
		stack->stack_b->next->check = tmp;
	}
	else
		return ;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack, int print)
{
	if (stack->len_a > 1 && stack->len_b > 1)
	{
		sa(stack, 0);
		sb(stack, 0);
		if (print)
			write(1, "ss\n", 3);
	}
}
