/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:01:47 by amalangu          #+#    #+#             */
/*   Updated: 2025/04/01 17:09:24 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_stack_sorted(t_stack *stack)
{
	while (stack->next && head_index(stack) < next_index(stack))
		stack = stack->next;
	if (stack->next)
		return (0);
	else
		return (1);
}

int	get_index(long *args, int i, int size)
{
	int	index;
	int	j;

	j = -1;
	index = 0;
	while (++j < size)
	{
		if (args[j] < i)
			index++;
	}
	return (index);
}

//set final index in list
void	set_index(t_stack **head, long *args, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = *head;
	i = 0;
	while (i < size)
	{
		tmp->index = get_index(args, args[i++], size);
		tmp = tmp->next;
	}
}
