/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:34:09 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/09/30 11:51:17 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stacks(t_stack *stack, t_node *tmp_a, t_node *tmp_b)
// {
// 	int	i;

// 	i = 0;
// 	while (stack->len_a > i || stack->len_b > i)
// 	{
// 		if (stack->len_a > i)
// 		{
// 			printf("n a = %d, i = %d, check = %d\n", tmp_a->num, tmp_a->index, tmp_a->check);
// 			tmp_a = tmp_a->next;	
// 		}
// 		else
// 			printf("_______________");
// 		if (stack->len_b > i)
// 		{
// 			printf("n b = %d, i = %d, check = %d\n", tmp_b->num, tmp_b->index, tmp_b->check);
// 			tmp_b = tmp_b->next;	
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	printf("_______________\n");
// }

void	color(t_stack *stack)
{
	getchar();
	system("clear");
	ft_putstr_fd("\033[01;38;05;226;48;05;97m", 1);
	ft_putnbr_fd(stack->len_a, 1);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd("\033[36;1m ---- stack a -----|  \033[0m", 1);
	ft_putnbr_fd(stack->len_b, 1);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd("\033[36;1m|------ stack b -----|\033[0m\n", 1);
	ft_putstr_fd("num\tindex\tcheck\tnum\tindex\tcheck\033[0m\n", 1);
}

void	print_stacks(t_stack *stack, t_node *tmp_a, t_node	*tmp_b)
{
	int		i;

	color(stack);
	i = 0;
	while (stack->len_a > i || stack->len_b > i)
	{
		if (stack->len_a > i)
		{
			printf("%d\t%d\t%d\t", tmp_a->num, tmp_a->index, tmp_a->check);
			tmp_a = tmp_a->next;
		}
		else
			printf("\t\t\t");
		if (stack->len_b > i)
		{
			printf("%d\t%d\t%d", tmp_b->num, tmp_b->index, tmp_b->check);
			tmp_b = tmp_b->next;
		}
		printf("\n");
		i++;
	}
	ft_putstr_fd("\033[36;1m--------------------|  \033[0m", 1);
	ft_putstr_fd("\033[36;1m|--------------------|\033[0m\n", 1);
}


