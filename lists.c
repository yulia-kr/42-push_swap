/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:16:52 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/09/30 10:52:25 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(char **arr)
{
	t_stack	*stack;
	int		i;

	i = 0;
	while (arr[i])
		i++;
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->len_a = i;
	stack->len_b = 0;
	stack->btm_a = 1;
	return (stack);
}

t_node	*new_list(int num, int index)
{
	t_node	*list;

	list = malloc(sizeof(t_node));
	if (list == NULL)
		return (NULL);
	list->num = num;
	list->check = 0;
	list->index = index;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void	lstadd_back(t_node **stack_a, t_node *new)
{
	t_node	*first;

	if (new == NULL)
		return ;
	first = *stack_a;
	if (first)
	{
		if (first->prev)
		{
			first->prev->next = new;
			new->prev = first->prev;
			new->next = first;
			first->prev = new;
		}
		else
		{
			first->prev = new;
			first->next = new;
			new->prev = first;
			new->next = first;
		}
	}
	else
		*stack_a = new;
	return ;
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->len_a--)
	{
		tmp = stack->stack_a->next;
		free(stack->stack_a);
		stack->stack_a = NULL;
		stack->stack_a = tmp;
	}
	while (stack->len_b--)
	{
		tmp = stack->stack_b->next;
		free(stack->stack_b);
		stack->stack_b = NULL;
		stack->stack_b = tmp;
	}
	free(stack);
	exit(0);
}
