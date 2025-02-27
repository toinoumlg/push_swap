/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:08:30 by amalangu          #+#    #+#             */
/*   Updated: 2025/02/27 18:08:42 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *stack, char a_or_b)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->i;
	stack->i = stack->next->i;
	stack->next->i = tmp;
	if (a_or_b == 'a')
		ft_printf("sa\n");
	else if (a_or_b == 'b')
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a && a->next)
	{
		tmp = a->i;
		a->i = a->next->i;
		a->next->i = tmp;
	}
	if (b && b->next)
	{
		tmp = b->i;
		b->i = b->next->i;
		b->next->i = tmp;
	}
	ft_printf("ss\n");
}
