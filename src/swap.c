/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:08:30 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/18 14:53:34 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack **stack, char a_or_b)
{
	t_stack	*head;
	t_stack	*next;

	head = *stack;
	if (!head || !head->next)
		return ;
	next = head->next;
	head->next = next->next;
	next->next = head;
	*stack = next;
	
	if (a_or_b)
		ft_printf("s%c\n", a_or_b);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a, 0);
	swap(b, 0);
	ft_printf("ss\n");
}
