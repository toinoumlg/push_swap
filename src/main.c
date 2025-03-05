/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:43:42 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/05 19:15:11 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_list_sorted(t_stack *stack)
{
	while (stack->next && stack->i < stack->next->i)
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
	while (stack && ++i)
		stack = stack->next;
	return (i);
}

void	three(t_stack **a, t_stack **b)
{
	t_stack	*head_a;
	t_stack	*head_b;

	push_b(a, b);
	head_a = *a;
	if (head_a->i > head_a->next->i)
		rotate(a, 'a');
	head_b = *b;
	head_a = *a;
	if (head_a->i < head_b->i && head_a->next->i < head_b->i)
		push_a(a, b);
}

void	algo_small(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		return (rotate(a, 'a'));
	if (size == 3)
		return (three(a, b));
	(void)a;
	(void)b;
}

void	algo_big(t_stack **a, t_stack **b, int size)
{
	(void)a;
	(void)size;
	(void)b;
}
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (ac < 2)
		return (ft_printf("Error\nDoesnt have args"), -1);
	a = set_stack(av, ac);
	b = NULL;
	if (!a)
		return (-1);
	if (is_list_sorted(a))
		return (free_stack(a), ft_printf("list is already sorted\n"), 0);
	size = list_size(a);
	if (size <= 5)
		algo_small(&a, &b, size);
	else
		algo_big(&a, &b, size);
	print_stacks(a, b);
	free_stack(a);
	free_stack(b);
}
