/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:43:42 by amalangu          #+#    #+#             */
/*   Updated: 2025/04/04 12:30:14 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (ft_putstr_fd("Error\n", 2), -1);
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
	return (free_stack(a), free_stack(b), 0);
}
