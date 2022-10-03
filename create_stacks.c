/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:13:46 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/09/30 12:04:49 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stack *stack, int *sort, int *unsort, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (unsort[i] == sort[j])
			{
				lstadd_back(&stack->stack_a, new_list(unsort[i], j + 1));
				j++;
				break ;
			}
			j++;
		}
		// printf("bubble stack i %d = sort %d\n", i, sort[i]);
		i++;
	}
	free(unsort);
	free(sort);
}

void	bubble_sort(t_stack *stack, int *sort, int *unsort, int len)
{
	int	i;
	int	j;
	int	tmp;
	int	count;

	i = 0;
	count = 0;
	while (i < len)
	{
		j = 0;
		while (j < (len - 1 - i))
		{
			if(sort[j] > sort[j + 1])
			{
				tmp = sort[j + 1];
				sort[j + 1] = sort[j];
				sort[j] = tmp;
				count++;
			}
			j++;
		}
		i++;
	}
	create_stack(stack, sort, unsort, len);
}

void	fill_stack(t_stack *stack, char **arr)
{
	int *unsort;
	int *sort;
	int i;
	int nb;
	int len;

	len = 0;
	i = -1;
	while (arr[++i])
		len++;
	unsort = malloc(sizeof(int) * (len));
	sort = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		nb = ft_atoi(arr[i]);
		unsort[i] = nb;
		sort[i] = nb;
		// printf("stack i %d = unsort %d\n", i, unsort[i]);
		i++;
	}
	bubble_sort(stack, sort, unsort, len);
}