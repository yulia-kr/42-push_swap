/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:32:17 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/10/02 13:10:31 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main (int ac, char **av)
// {	
// 	t_stack *stack = NULL;
// 	t_node *tmpa;
// 	t_node *tmpb;
// 	char **arr;
	
// 	if (ac > 1)
// 	{
// 		arr = get_line(av);
// 		check_num(arr);
// 		check_doubles(arr);
// 		// while (*arr)
// 		// {
// 		// 	printf("main %s\n", *arr);
// 		// 	arr++;
// 		// }
// 		// return 0;
// 		stack = init_stack(arr);
// 		fill_stack(stack, arr);
// 		free_ps(arr, 0);
// 		// tmpa = stack->stack_a;
// 		// tmpb = stack->stack_b;
// 		// print_stacks(stack, tmpa, tmpb);
// 		printf ("\n");
// 		if (sort_done(stack))
// 			free_stack(stack);
// 		if (stack->len_a < 6)
// 		{
// 			sort_five(stack);
// 			free_stack(stack);
// 		}
// 		med_division_first(stack);
// 		while(!(sort_done(stack)) && stack->len_b == 0)
// 		{
// 			if (stack->len_b > 0 && stack->len_b < 6)
// 				push_a_five(stack);
// 			else if(stack->len_b >= 6)
// 				move_minb(stack);
// 			if (stack->len_b == 0)
// 			{
// 				push_b_five(stack, 0, 0, 0);
// 				move_mina(stack);
// 			}
// 		}
// 		printf ("\n");
// 		tmpa = stack->stack_a;
// 		tmpb = stack->stack_b;
// 		print_stacks(stack, tmpa, tmpb);
// 		// printf ("\n");
// 		// free_ps(arr, 0);
// 		// free_stack(stack);
// 	}
// 	printf ("\n");
// 	tmpa = stack->stack_a;
// 	tmpb = stack->stack_b;
// 	print_stacks(stack, tmpa, tmpb);
// 	return 0;
// }	


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

// void sorting(t_stack *stack)
// {	
// 	if (sort_done(stack))
// 		free_stack(stack);
// 	if (stack->len_a < 6)
// 	{
// 		sort_five(stack);
// 		// print_stacks(stack, stack->stack_a, stack->stack_b);
// 		free_stack(stack);
// 	}
// 	med_division_first(stack);
// 	while (!(sort_done(stack) && stack->len_b == 0))
// 	{	
// 		//
// 		// printf("sort done = %d\n", sort_done(stack));
// 		// printf("len b = %d\n", stack->len_b);
// 		if (stack->len_b > 0 && stack->len_b < 6)
// 			push_b_five(stack);
// 		else if (stack->len_b >= 6)
// 			move_minb(stack);
// 		// print_stacks(stack, stack->stack_a, stack->stack_b);
// 		if(stack->len_b == 0)
// 		{	
// 			push_a_five(stack, 0, 0, 0);
// 			//
// 			// printf("sort done = %d\n", sort_done(stack));
// 			// printf("len b = %d\n", stack->len_b);
// 			// print_stacks(stack, stack->stack_a, stack->stack_b);
// 			move_mina(stack);
// 		}
// 	}
// }

void	sorting(t_stack *stack)
{
	if (sort_done(stack))
		free_stack(stack);
	if (stack->len_a < 6)
	{
		sort_five(stack);
		free_stack(stack);
	}
	med_division_first(stack);
	// printf("med division stack\n");
	// print_stacks(stack, stack->stack_a, stack->stack_b);
	while (!(sort_done(stack) && stack->len_b == 0))
	{
		if (stack->len_b > 0 && stack->len_b < 4)
			sort_three_b(stack);
		else if (stack->len_b >= 4)
			move_minb(stack);
		if (stack->len_b == 0)
		{
			// printf("sort done = %d\n", sort_done(stack));
 			// printf("len b = %d\n", stack->len_b);
 			// print_stacks(stack, stack->stack_a, stack->stack_b);
			move_mina(stack);
		}
	}
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
		// print_stacks(all, all->stack_a, all->stack_b);
		free_stack(stack);
	}
	return (0);
}
