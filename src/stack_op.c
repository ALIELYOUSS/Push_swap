/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:11:31 by alel-you          #+#    #+#             */
/*   Updated: 2025/02/17 15:23:14 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clear_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

int	push_to_stack(t_stack **stack, int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (-1);
	node->content = content;
	node->next = NULL;
	node->prv = NULL;
	node->index = -1;
	if ((*stack) == NULL)
	{
		(*stack) = node;
		return (1);
	}
	ft_add_back(stack, node);
	return (1);
}

int	stack_size(t_stack *stack)
{
	t_stack	*tmp;
	int		size;

	tmp = stack;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

t_stack	*ft_stack_last(t_stack *lst)
{
	t_stack	*last_node;

	if (!lst)
		return (NULL);
	last_node = lst;
	while (last_node->next)
	{
		last_node = last_node->next;
	}
	return (last_node);
}

void	ft_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last_node = ft_stack_last(*lst);
		new->prv = last_node;
		last_node->next = new;
	}
}
