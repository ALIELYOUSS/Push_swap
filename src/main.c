/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:37:20 by alel-you          #+#    #+#             */
/*   Updated: 2025/02/17 14:46:30 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (is_sorted(*stack_a) == -1 && size == 2)
		sa(stack_a);
	else if (is_sorted(*stack_a) == -1 && size == 3)
		sort_3(stack_a);
	else if (is_sorted(*stack_a) == -1 && size == 4)
		sort_4(stack_a, stack_b);
	else if (is_sorted(*stack_a) == -1 && size == 5)
		sort_5(stack_a, stack_b);
	else if (is_sorted(*stack_a) == -1 && size > 5)
		sort_kolsi(stack_a, stack_b);
}

static char	*join_args(int ac, char **av)
{
	char	*joined_args;
	char	*pre;
	int		i;

	i = 1;
	joined_args = NULL;
	while (i < ac)
	{
		pre = joined_args;
		joined_args = ft_strjoin(joined_args, av[i]);
		free(pre);
		pre = joined_args;
		joined_args = ft_strjoin(joined_args, " ");
		free(pre);
		i++;
	}
	return (joined_args);
}

static void	free_2d(char **td)
{
	int	i;

	i = 0;
	while (td[i])
	{
		free(td[i]);
		i++;
	}
	free(td);
}

static int	fill_stack(t_stack **stack_a, char *joined_args)
{
	char	**splited_args;
	int		i;
	long	num;

	splited_args = ft_split(joined_args, ' ');
	i = 0;
	while (splited_args[i])
	{
		if (ft_isdigit_s(splited_args[i]) == 0)
			return (free_2d(splited_args), \
			clear_stack(stack_a), ft_putstr_fd("Error\n", 1), 0);
		num = ft_atoi(splited_args[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (free_2d(splited_args), \
			clear_stack(stack_a), ft_putstr_fd("Error\n", 1), 0);
		if (isdup(*stack_a, num) == -1)
			return (free_2d(splited_args), \
			clear_stack(stack_a), ft_putstr_fd("Error\n", 1), 0);
		if (!push_to_stack(stack_a, num))
			return (free_2d(splited_args), \
			clear_stack(stack_a), ft_putstr_fd("Error\n", 1), 0);
		i++;
	}
	free_2d(splited_args);
	return (1);
}

int	main(int ac, char**av)
{
	char	*joined_args;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	joined_args = join_args(ac, av);
	if (fill_stack(&stack_a, joined_args) == 0)
	{
		free(joined_args);
		return (0);
	}
	free(joined_args);
	set_index_stack(stack_a);
	sort_all(&stack_a, &stack_b);
	clear_stack(&stack_a);
	clear_stack(&stack_b);
}
