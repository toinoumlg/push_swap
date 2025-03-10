/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:43:42 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/10 20:58:13 by amalangu         ###   ########.fr       */
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

void	algo_small(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		return (rotate(a, 'a'));
	if (size == 3)
		return (three(a, b));
}

void	push_b_odd(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (tail_index(*b) % 2 == 0)
		return (push_b(a, b), rotate(b, 'b'));
	if (head_index(*a) > tail_index(*b))
		return (push_b(a, b), rotate(b, 'b'));
	while (head_index(*a) < tail_index(*b))
	{
		reverse_rotate(b, 'b');
		i++;
	}
	push_b(a, b);
	while (i > 0 && head_index(*b) % 2 != 1)
	{
		rotate(b, 'b');
		i--;
	}
}

void	push_b_even(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (head_index(*b) % 2 == 1)
		return (push_b(a, b));
	if (head_index(*a) > head_index(*b))
		return (push_b(a, b));
	while (head_index(*a) < head_index(*b))
	{
		rotate(b, 'b');
		if (head_index(*b) % 2 == 1)
			break ;
		i++;
	}
	push_b(a, b);
	while (i > 0 && head_index(*b) % 2 != 0)
	{
		reverse_rotate(b, 'b');
		i--;
	}
}

void	revert_a(t_stack **a, t_stack **b, int i)
{
	int	j;

	if (stack_size(*a) == 2)
		return ;
	push_b(a, b);
	j = i;
	while (i > 0)
	{
		reverse_rotate(a, 'a');
		i--;
	}
	push_a(a, b);
	while (j > 0)
	{
		rotate(a, 'a');
		j--;
	}
}

void	push_b_split(t_stack **a, t_stack **b, int size)
{
	push_b(a, b);
	ft_printf("%d\n", size);
	if (stack_size(*a) == 1)
		return print_stacks(*a, *b);
	if (head_index(*a) == size)
		return (rotate(a, 'a'), push_b_split(a, b, size));
	if (head_index(*a) % 2 == 0)
		return (push_b_even(a, b), push_b_split(a, b, size));
	if (head_index(*a) % 2 == 1)
		return (push_b_odd(a, b), push_b_split(a, b, size));
	
}

void	algo_big(t_stack **a, t_stack **b)
{
	push_b_split(a, b, stack_size(*a));
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
	if (stack_size(a) <= 3)
		algo_small(&a, &b, stack_size(a));
	else
		algo_big(&a, &b);
	free_stack(a);
	free_stack(b);
}
