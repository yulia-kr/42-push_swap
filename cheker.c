/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:25:28 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/10/02 11:10:41 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	operations(t_stack *stack, char *line)
{
	if (!ft_strncmp(line, "pa\n", 3))
		pa(stack, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(stack, 0);
	else if (!ft_strncmp(line, "sa\n", 3))
		sa(stack, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(stack, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(stack, 0);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(stack, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(stack, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(stack, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(stack, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(stack, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(stack, 0);
	else
		error();
}

static void	checker(t_stack *stack)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		operations(stack, line);
	}
	if (sort_done(stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

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

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac > 1)
	{
		stack = parsing(av);
		checker(stack);
		free_stack(stack);
	}
	return (0);
}

