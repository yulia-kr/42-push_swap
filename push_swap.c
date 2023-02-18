/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:32:17 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/10/07 11:44:14 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parsing(char **av)
{
	t_stack	*stack;
	char	**arr;

	arr = get_line(av);
	check_num(arr);
	check_doubles(arr);
	stack = init_stack(arr);
	fill_stack(stack, arr);
	free_ps(arr, 0);
	return (stack);
}

void	sorting(t_stack *stack)
{
	if (sort_done(stack))
		free_stack(stack);
	if (stack->len_a < 6)
	{
		sort_five(stack);
		free_stack(stack);
	}
	med_division(stack);
	while (!(sort_done(stack) && stack->len_b == 0))
	{
		if (stack->len_b > 0 && stack->len_b < 6)
			push_b_to_a(stack);
		else if (stack->len_b >= 6)
			move_minb(stack);
		if (stack->len_b == 0)
		{
			push_a_to_b(stack, 0, 0, 0);
			move_mina(stack);
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac > 1)
	{
		stack = parsing(av);
		sorting(stack);
		free_stack(stack);
	}
	return (0);
}
