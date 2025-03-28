/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:01:47 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/28 16:32:50 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_index(long *args, int i, int size)
{
	int	index;
	int	j;

	j = -1;
	index = 0;
	ft_printf("i %d\n size %d");
	while (++j < size)
	{
		if (args[j] < i)
			index++;
	}
	return (index);
}

void	set_index(t_stack **head, long *args, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = *head;
	i = 0;
	while (i < size)
	{
		tmp->index = get_index(args, args[i++], size);
		tmp = tmp->next;
	}
}
