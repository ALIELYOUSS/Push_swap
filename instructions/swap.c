/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:11:31 by alel-you          #+#    #+#             */
/*   Updated: 2025/02/15 15:45:17 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack **a, char *text)
{
	int	tmp;

	if (stack_size(*a) <= 1)
		return ;
	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	if (text)
		ft_putstr_fd(text, 1);
}

void	sa(t_stack **a)
{
	swap(a, "sa\n");
}

void	sb(t_stack **b)
{
	swap(b, "sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a, NULL);
	swap(b, "ss\n");
}
