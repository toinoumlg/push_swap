/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:22:06 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/20 18:40:58 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	radx(t_stack **a, t_stack **b, int size)
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
