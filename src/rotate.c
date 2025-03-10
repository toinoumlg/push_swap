/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:27:16 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/10 20:18:47 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	ft_printf("rrr\n");
}

void	reverse_rotate(t_stack **stack, char a_or_b)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*head;

	tmp = *stack;
	if (!tmp || !tmp->next)
		return ;
	head = tmp;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = head;
	*stack = last;
	if (a_or_b)
		ft_printf("rr%c\n", a_or_b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr\n");
}

void	rotate(t_stack **stack, char a_or_b)
{
	t_stack	*tmp;
	t_stack	*head;
	t_stack	*first;

	tmp = *stack;
	if (!tmp || !tmp->next)
		return ;
	first = *stack;
	head = tmp->next;
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	tmp = tmp->next;
	tmp->next = NULL;
	*stack = head;
	if (a_or_b)
		ft_printf("r%c\n", a_or_b);
}
