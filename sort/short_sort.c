/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:57:16 by alel-you          #+#    #+#             */
/*   Updated: 2025/02/17 14:46:56 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	help_sort3(t_stack *current, t_stack *last)
{
	if (current->content < last->content && current->content > \
		current->next->content && last->content > current->next->content)
		return (0);
	if (current->content > last->content && last->content < \
		current->next->content && current->content > current->next->content)
		return (1);
	if (current->content > current->next->content && current->content > \
		last->content && last->content > current->next->content)
		return (2);
	if (current->content < current->next->content && current->content < \
		last->content && last->content < current->next->content)
		return (3);
	if (current->content < current->next->content && current->content > \
		last->content && last->content < current->next->content)
		return (4);
	return (-1);
}

void	sort_3(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*current;

	tmp = ft_stack_last(*stack_a);
	current = (*stack_a);
	if (help_sort3(current, tmp) == 0)
		sa(stack_a);
	else if (help_sort3(current, tmp) == 1)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (help_sort3(current, tmp) == 2)
		ra(stack_a);
	else if (help_sort3(current, tmp) == 3)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (help_sort3(current, tmp) == 4)
		rra(stack_a);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	ra_reap;
	int	size;

	ra_reap = get_min_index(*stack_a);
	if (ra_reap < (stack_size(*stack_a) / 2))
	{
		while (ra_reap--)
			ra(stack_a);
	}
	else if (ra_reap >= (stack_size(*stack_a) / 2))
	{
		size = stack_size(*stack_a) - ra_reap;
		while (size--)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		ra_reap;

	if (!stack_a || !*stack_a)
		return ;
	ra_reap = get_min_index(*stack_a);
	tmp = (*stack_a);
	if (ra_reap <= (stack_size(*stack_a) / 2))
	{
		while (ra_reap--)
			ra(stack_a);
	}
	else if (ra_reap > (stack_size(*stack_a) / 2))
	{
		ra_reap = stack_size(*stack_a) - ra_reap;
		while (ra_reap--)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_b, stack_a);
}
