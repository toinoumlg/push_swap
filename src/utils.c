/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:28:21 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/04 16:28:45 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = a;
	tmp_b = b;
	ft_printf("stacks\na ---- b\n");
	while (tmp_a || tmp_b)
	{
		if (tmp_a && tmp_b)
			ft_printf("[%d] - [%d]\n", tmp_a->i, tmp_b->i);
		else if (tmp_a)
			ft_printf("[%d] - []\n", tmp_a->i);
		else
			ft_printf("[] - [%d]\n", tmp_b->i);
		if (tmp_a)
			tmp_a = tmp_a->next;
		if (tmp_b)
			tmp_b = tmp_b->next;
	}
}
