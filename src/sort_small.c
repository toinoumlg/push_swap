/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:27:41 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/20 19:08:28 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **stack)
{
	if (head_index(*stack) > next_index(*stack)
		&& next_index(*stack) < tail_index(*stack)
		&& head_index(*stack) < tail_index(*stack))
		swap(stack, 'a');
	else if (head_index(*stack) > next_index(*stack)
		&& next_index(*stack) > tail_index(*stack))
	{
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
	}
	else if (head_index(*stack) > next_index(*stack)
		&& head_index(*stack) > tail_index(*stack))
		rotate(stack, 'a');
	else if (head_index(*stack) < next_index(*stack)
		&& head_index(*stack) > tail_index(*stack))
		reverse_rotate(stack, 'a');
	else if (head_index(*stack) < next_index(*stack)
		&& next_index(*stack) > tail_index(*stack))
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
}

void	get_min_position(t_stack *stack, int *min_index, int *position)
{
	*min_index = 5;
	*position = 0;
	while (stack)
	{
		if (head_index(stack) < *min_index)
		{
			*min_index = head_index(stack);
			*position = 0;
			while (stack && head_index(stack) != *min_index)
			{
				*position = *position + 1;
				stack = stack->next;
			}
		}
		else
			stack = stack->next;
	}
}

void	set_stack_to_three(t_stack **a, t_stack **b)
{
	int	position;
	int	min_index;

	while (stack_size(*a) > 3)
	{
		get_min_position(*a, &min_index, &position);
		while (head_index(*a) != min_index)
		{
			if (position < stack_size(*a) / 2)
				rotate(a, 'a');
			else
				reverse_rotate(a, 'a');
		}
		push_b(a, b);
	}
}

void	sort_small(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		return (rotate(a, 'a'));
	else if (size == 3)
		return (sort_three(a));
	else
	{
		set_stack_to_three(a, b);
		sort_three(a);
		while (*b)
			push_a(a, b);
	}
}
