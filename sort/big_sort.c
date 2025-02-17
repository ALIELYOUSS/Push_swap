/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:19:19 by alel-you          #+#    #+#             */
/*   Updated: 2025/02/17 14:55:18 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	half_top_or_bottom(t_stack *stack, int biggest_index)
{
	int		i;
	int		median;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	if (!tmp)
		return (0);
	median = stack_size(tmp) / 2;
	while (tmp)
	{
		if (tmp->index == biggest_index)
		{
			if (i < median)
				return (1);
		}
		tmp = tmp->next;
		i++;
	}
	return (0);
}

static void	push_to_a(t_stack **a, t_stack **b)
{
	int	biggest_index;

	biggest_index = stack_size(*b) - 1;
	while (*b)
	{
		if ((*b)->index == biggest_index)
		{
			pa(b, a);
			biggest_index--;
		}
		else
		{
			if (half_top_or_bottom(*b, biggest_index))
				rb(b);
			else
				rrb(b);
		}
	}
}

static int	get_range(int size)
{
	int	range;

	range = 0;
	if (size <= 100)
		range = 15;
	else if (size > 100)
		range = 30;
	return (range);
}

void	sort_kolsi(t_stack **a, t_stack **b)
{
	int	range;
	int	i;

	if (!a || !*a)
		return ;
	range = get_range(stack_size(*a));
	i = 0;
	while (stack_size(*a) != 0)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index < (i + range))
		{
			pb(a, b);
			if (b && (*b)->next)
				rb(b);
			i++;
		}
		else
			ra(a);
	}
	push_to_a(a, b);
}
