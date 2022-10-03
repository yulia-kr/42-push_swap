/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykruhlyk <ykruhlyk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 09:57:48 by ykruhlyk          #+#    #+#             */
/*   Updated: 2022/09/30 12:02:35 by ykruhlyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	free_ps(char **arr, int print)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	if (print)
		error();
}

void	check_num(char **arr)
{
	int	i;
	int	j;
	long long	num;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while(arr[i][j])
		{
			if(arr[i][j] == '-')
				j++;
			if (!(ft_isdigit(arr[i][j])))
				free_ps(arr, 1);
			j++;
		}
		num = ft_atoi(arr[i]);
		if (num < MIN_INT || num > MAX_INT)
			free_ps(arr, 1);
		i++;
	}
}

void	check_doubles(char **arr)
{
	int	i;
	int	j;
	
	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				free_ps(arr, 1);
			j++;
		}
		i++;
	}
}

char	**get_line(char **av)
{
	int		i;
	char	*line;
	char	*tmp;
	char	**arr;

	line = ft_strdup(av[1]);
	i = 2;
	while(av[i])
	{
		tmp = line;
		line = ft_strjoin(line, " ");
		free(tmp);
		tmp = line;
		line = ft_strjoin(line, av[i]);
		free(tmp);
		i++;
	}
	arr = ft_split(line, ' ');
	free(line);
	// while (*arr)
	// {
	// 	printf("%s\n", *arr);
	// 	arr++;
	// }
	return(arr);
}
