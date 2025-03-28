/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:43:42 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/28 21:21:08 by amalangu         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (ft_printf("Error\n"), -1);
	a = set_stack(av, ac);
	b = NULL;
	if (!a)
		return (-1);
	if (is_stack_sorted(a))
		return (free_stack(a), 0);
	if (stack_size(a) <= 5)
		sort_small(&a, &b, stack_size(a));
	else
		radx(&a, &b, stack_size(a));
	free_stack(a);
	free_stack(b);
}
