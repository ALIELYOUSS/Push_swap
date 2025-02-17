/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:36:55 by alel-you          #+#    #+#             */
/*   Updated: 2025/02/16 21:28:31 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				range;
	int				content;
	int				index;
	struct s_node	*prv;
	struct s_node	*next;
}	t_stack;
//
void	print_stack(t_stack *stack);
int		isdup(t_stack *stack, int number);
char	*ft_strjoin(char *s1, const char *s2);
int		ft_isdigit_s(char *str);
//
int		push_to_stack(t_stack **stack, int content);
int		get_min_index(t_stack *stack_a);
int		stack_size(t_stack *stack);
void	clear_stack(t_stack **stack);
void	ft_add_back(t_stack **lst, t_stack *new);
void	set_index_stack(t_stack *stack);
t_stack	*ft_stack_last(t_stack *lst);
//
void	reverse_rotate(t_stack *s, char *text);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
//
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
//
void	rb(t_stack **s_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **s_a);
//
void	rra(t_stack **s);
void	rrb(t_stack **s);
void	rrr(t_stack **a, t_stack **b);
//
void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	sort_kolsi(t_stack **a, t_stack **b);
int		is_sorted(t_stack *stack);

#endif