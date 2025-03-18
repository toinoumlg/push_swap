/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:43:42 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/18 15:07:30 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	head_value(t_stack *stack)
{
	return (stack->i);
}

int	next_value(t_stack *stack)
{
	if (stack->next)
		return (stack->next->i);
	return (-1);
}

int	tail_value(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->i);
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

int	is_list_sorted(t_stack *stack)
{
	while (stack->next && head_value(stack) < next_value(stack))
		stack = stack->next;
	if (stack->next)
		return (0);
	else
		return (1);
}

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack && ++i)
		stack = stack->next;
	return (i);
}

void	three(t_stack **a, t_stack **b)
{
	push_b(a, b);
	if (head_value(*a) > next_value(*a))
		rotate(a, 'a');
	if (head_value(*a) < head_value(*b) && next_value(*a) < head_value(*b))
		return (push_a(a, b), rotate(a, 'a'));
	if (head_value(*a) > head_value(*b))
		return (push_a(a, b));
	if (head_value(*a) < head_value(*b) && next_value(*a) > head_value(*b))
		return (rotate(a, 'a'), push_a(a, b), reverse_rotate(a, 'a'));
}

void	insert_back_b(t_stack **a, t_stack **b, int head)
{
	while (head_index(*b) < head_index(*a) && head_index(*b)> next_index())
		rotate(a, 'a');
	push_a(a, b);
	while (head_index(*a) != head)
		reverse_rotate(a, 'a');
}

void	less_than_five(t_stack **a, t_stack **b)
{
	while (stack_size(*a) != 3)
		push_b(a, b);
	three(a, b);
	while (stack_size(*b) != 0)
		insert_back_b(a, b, head_index(*a));
}

void	algo_small(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		return (rotate(a, 'a'));
	if (size == 3)
		return (three(a, b));
	else
		return (less_than_five(a, b));
}

void	algo_big(t_stack **a, t_stack **b, int size)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;

	max_num = size - 1;
	max_bits = 0;
	i = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((head_index(*a) >> i) & 1) == 1)
				rotate(a, 'a');
			else
				push_b(a, b);
			++j;
		}
		while (stack_size(*b) != 0)
			push_a(a, b);
		++i;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (ft_printf("Error\nDoesnt have args"), -1);
	a = set_stack(av, ac);
	b = NULL;
	if (!a)
		return (-1);
	if (is_list_sorted(a))
		return (free_stack(a), ft_printf("list is already sorted\n"), 0);
	if (stack_size(a) <= 5)
		algo_small(&a, &b, stack_size(a));
	else
		algo_big(&a, &b, stack_size(a));
	free_stack(a);
	free_stack(b);
}
