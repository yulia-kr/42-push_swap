/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:50:01 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/09/26 09:58:25 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack, int print)
{
	if (stack->len_a > 1)
		stack->stack_a = stack->stack_a->prev;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, int print)
{
	if (stack->len_b > 1)
		stack->stack_b = stack->stack_b->prev;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack, int print)
{
	if (stack->len_a > 1 && stack->len_b > 1)
	{
		rra(stack, 0);
		rrb(stack, 0);
		if (print)
			write(1, "rrr\n", 4);
	}
}
