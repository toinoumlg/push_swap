/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:07:46 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/04 16:59:09 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*swap;

	swap = *b;
	if (!swap)
		return ;
	*b = swap->next;
	swap->next = *a;
	*a = swap;
	ft_printf("pa\n");
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*swap;

	swap = *a;
	if (!swap)
		return ;
	*a = swap->next;
	swap->next = *b;
	*b = swap;
	ft_printf("pb\n");
}
