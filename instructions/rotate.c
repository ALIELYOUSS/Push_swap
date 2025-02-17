/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:42:04 by alel-you          #+#    #+#             */
/*   Updated: 2025/02/15 15:44:13 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack **stack, char *text)
{
	t_stack	*t;
	t_stack	*l;

	l = ft_stack_last((*stack));
	t = (*stack)->next;
	(*stack)->next = NULL;
	(*stack)->prv = l;
	l->next = (*stack);
	*stack = t;
	if (text)
		ft_putstr_fd(text, 1);
}

void	ra(t_stack **s_a)
{
	rotate(s_a, "ra\n");
}

void	rb(t_stack **s_b)
{
	rotate(s_b, "rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, NULL);
	rotate(stack_b, "rr\n");
}
