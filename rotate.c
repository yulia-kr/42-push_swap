/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:44:13 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/09/26 09:49:39 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack, int print)
{
	if (stack->len_a > 1)
		stack->stack_a = stack->stack_a->next;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int print)
{
	if (stack->len_b > 1)
		stack->stack_b = stack->stack_b->next;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack, int print)
{
	if (stack->len_a > 1 && stack->len_b > 1)
	{
		ra(stack, 0);
		rb(stack, 0);
		if (print)
			write(1, "rr\n", 3);
	}
}
