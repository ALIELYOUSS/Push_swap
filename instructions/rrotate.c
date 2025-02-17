/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:41:59 by alel-you          #+#    #+#             */
/*   Updated: 2025/02/15 15:44:38 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	r_rotate(t_stack **stack, char *text)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = ft_stack_last(*stack);
	tmp1 = (*stack);
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	tmp1->next = NULL;
	tmp1->prv = tmp->prv;
	tmp->next = (*stack);
	(*stack) = tmp;
	if (text)
		ft_putstr_fd(text, 1);
}

void	rra(t_stack **s_a)
{
	r_rotate(s_a, "rra\n");
}

void	rrb(t_stack **s_b)
{
	r_rotate(s_b, "rrb\n");
}

void	rrr(t_stack **s_a, t_stack **s_b)
{
	r_rotate(s_a, NULL);
	r_rotate(s_b, "rrr\n");
}
