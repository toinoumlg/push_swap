/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:43:42 by amalangu          #+#    #+#             */
/*   Updated: 2025/02/27 18:10:20 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void rotate(t_stack **stack, char a_or_b)
{
	
}

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	a = set_stack();
	b = NULL;
	if (!a)
		return (-1);
	print_stack(a);
	swap(a, 'a');
	ss(a, b);
	push_b(&a, &b);
	push_b(&a, &b);
	push_b(&a, &b);
	push_b(&a, &b);
	push_b(&a, &b);
	push_b(&a, &b);
	push_a(&a, &b);
	push_a(&a, &b);
	push_a(&a, &b);
	push_a(&a, &b);
	push_a(&a, &b);
	push_a(&a, &b);
	print_stacks(a, b);
	free_stack(a);
	free_stack(b);
}
