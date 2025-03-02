/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:43:42 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/02 19:28:01 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void rotate(t_stack **stack, char a_or_b)
// {

// }

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac != 2)
		return (ft_printf("Error\nDoesnt have 2 args"), -1);
	a = set_stack(av[1]);
	b = NULL;
	if (!a)
		return (-1);
	// swap(a, 'a');
	// ss(a, b);
	// print_stacks(a, b);
	push_b_new(&a, &b);
	// print_stacks(a, b);
	free_stack(a);
	free_stack(b);
}
