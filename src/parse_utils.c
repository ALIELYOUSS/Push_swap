/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:11:31 by alel-you          #+#    #+#             */
/*   Updated: 2025/02/17 15:23:59 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	isdup(t_stack *stack, int number)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->content == number)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}

static int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

static int	is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && is_sign(str[i + 1]) == 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdigit_s(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' && str[i + 1] == '-') || \
			(str[i] == '+' && str[i + 1] == '+'))
			return (0);
		if ((str[i] < '0' || str[i] > '9') && \
			(str[i] != ' ' && str[i] != '\t') \
			&& (str[i] != '-' && str[i] != '+'))
			return (0);
		i++;
	}
	if (is_valid(str) == 0)
		return (0);
	return (1);
}
