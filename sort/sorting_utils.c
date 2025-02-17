/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:24:50 by alel-you          #+#    #+#             */
/*   Updated: 2025/02/15 16:04:15 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min_index(t_stack *stack_a)
{
	t_stack	*tmp;
	int		min;
	int		pos;

	if (!stack_a)
		return (-1);
	pos = 0;
	tmp = stack_a;
	min = stack_size(stack_a);
	while (tmp)
	{
		if (min > tmp->index)
			min = tmp->index;
		tmp = tmp->next;
	}
	tmp = stack_a;
	while (tmp)
	{
		if (min == tmp->index)
			break ;
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (-1);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
