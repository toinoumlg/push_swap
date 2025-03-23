/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:23:48 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/20 19:08:33 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	head_index(t_stack *stack)
{
	return (stack->index);
}

int	next_index(t_stack *stack)
{
	if (stack->next)
		return (stack->next->index);
	return (-1);
}

int	tail_index(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->index);
}

int	tail_previous_index(t_stack *stack)
{
	while (stack->next->next)
		stack = stack->next;
	return (stack->index);
}

int	head_next_index(t_stack *stack)
{
	return (stack->index);
}
