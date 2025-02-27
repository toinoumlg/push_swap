/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:07:46 by amalangu          #+#    #+#             */
/*   Updated: 2025/02/27 18:07:56 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*swap;

	tmp = *a;
	if (!tmp)
		return ;
	swap = ft_calloc(sizeof(t_stack), 1);
	swap->i = tmp->i;
	tmp = tmp->next;
	free(*a);
	*a = tmp;
	tmp = *b;
	if (!tmp)
	{
		swap->next = NULL;
		*b = swap;
	}
	else
	{
		swap->next = *b;
		*b = swap;
	}
	ft_printf("pb\n");
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*swap;

	tmp = *b;
	if (!tmp)
		return ;
	swap = ft_calloc(sizeof(t_stack), 1);
	swap->i = tmp->i;
	tmp = tmp->next;
	free(*b);
	*b = tmp;
	tmp = *a;
	if (!tmp)
	{
		swap->next = NULL;
		*a = swap;
	}
	else
	{
		swap->next = *a;
		*a = swap;
	}
	ft_printf("pa\n");
}