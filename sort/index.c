/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:26:10 by alel-you          #+#    #+#             */
/*   Updated: 2025/02/15 16:03:55 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*get_min(t_stack *stack)
{
	t_stack	*head;
	t_stack	*min;

	head = stack;
	while (head)
	{
		if (head->index == -1)
		{
			min = head;
			break ;
		}
		head = head->next;
	}
	head = stack;
	if (head)
	{
		while (head)
		{
			if (head->index == -1 && head->content < min->content)
				min = head;
			head = head->next;
		}
	}
	return (min);
}

void	set_index_stack(t_stack *stack)
{
	t_stack	*head;
	int		index;

	if (!stack)
		return ;
	index = 0;
	head = get_min(stack);
	while (index < stack_size(stack))
	{
		head->index = index++;
		head = get_min(stack);
	}
}
