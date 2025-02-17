/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:45:21 by alel-you          #+#    #+#             */
/*   Updated: 2025/02/15 15:45:33 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack **sender, t_stack **receiver, char *text)
{
	t_stack	*tmp;

	if (!(*sender) || !(*sender))
		return ;
	tmp = (*sender);
	(*sender) = (*sender)->next;
	if (!(*receiver))
	{
		tmp->next = (*receiver);
		(*receiver) = tmp;
	}
	else
	{
		tmp->next = (*receiver);
		tmp->prv = (*receiver);
		(*receiver) = tmp;
	}
	if (text)
		ft_putstr_fd(text, 1);
}

void	pa(t_stack **b, t_stack **a)
{
	push(b, a, "pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b, "pb\n");
}
