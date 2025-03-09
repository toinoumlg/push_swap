/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:43:42 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/09 20:07:11 by amalangu         ###   ########.fr       */
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

int	is_list_sorted(t_stack *stack)
{
	while (stack->next && head_value(stack) < next_value(stack))
		stack = stack->next;
	if (stack->next)
		return (0);
	else
		return (1);
}

int	list_size(t_stack *stack)
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

void	algo_small(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		return (rotate(a, 'a'));
	if (size == 3)
		return (three(a, b));
}

void	push_b_reversed_order(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (!*b)
		return (push_b(a, b));
	// print_stacks(*a, *b);
	if (list_size(*b) < 2)
	{
		push_b(a, b);
		if (head_value(*b) < tail_value(*b))
			rotate(b, 'b');
		return ;
	}
	if (head_value(*b) < head_value(*a))
		return (push_b(a, b));
	if (tail_value(*b) > head_value(*a))
		return (push_b(a, b), rotate(b, 'b'));
	while (!(head_value(*b) < head_value(*a)))
	{
		rotate(b, 'b');
		i++;
	}
	// ft_printf("%d\n", i);
	push_b(a, b);
	while (i > 0)
	{
		reverse_rotate(b, 'b');
		i--;
	}
}

void	insert_b_reversed(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	// print_stacks(*a, *b);
	if (head_value(*b) < head_value(*a))
		return (push_a(a, b));
	if (head_value(*b) > tail_value(*a))
		return (push_a(a, b), rotate(a, 'a'));
	while ((head_value(*b) > head_value(*a)))
	{
		rotate(a, 'a');
		i++;
	}
	// ft_printf("%d\n", i);
	push_a(a, b);
	while (i > 0)
	{
		reverse_rotate(a, 'a');
		i--;
	}
}

void	algo_big(t_stack **a, t_stack **b)
{
	while (list_size(*a) != 3)
		push_b_reversed_order(a, b);
	three(a, b);
	// print_stacks(*a, *b);
	while (list_size(*b) != 0)
		insert_b_reversed(a, b);
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
	// print_stacks(a, b);
	if (is_list_sorted(a))
		return (free_stack(a), ft_printf("list is already sorted\n"), 0);
	if (list_size(a) <= 3)
		algo_small(&a, &b, list_size(a));
	else
		algo_big(&a, &b);
	// print_stacks(a, b);
	free_stack(a);
	free_stack(b);
}
