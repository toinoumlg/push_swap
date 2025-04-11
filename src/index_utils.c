/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:23:48 by amalangu          #+#    #+#             */
/*   Updated: 2025/04/11 14:07:22 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strlen_no_0(char *str)
{
	int	i;

	i = 0;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9' && str)
	{
		i++;
		str++;
	}
	return (i);
}

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
