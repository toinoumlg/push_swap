/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:30:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/04 19:33:54 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		free(stack);
		stack = tmp;
	}
}

t_stack	*new_stack(int i)
{
	t_stack	*new;

	new = ft_calloc(sizeof(t_stack), 1);
	if (!new)
		return (NULL);
	new->i = i;
	new->next = NULL;
	return (new);
}

t_stack	*set_stack(char **av, int ac)
{
	t_stack	*new;
	t_stack	*head;
	t_stack	*tmp;
	int		i;
	int		*args;

	i = 0;
	args = set_up_args(av, ac);
	if (!args)
		return (NULL);
	head = new_stack(args[i]);
	if (!head)
		return (NULL);
	tmp = head;
	while (args[++i])
	{
		new = new_stack(args[i]);
		if (!new)
			return (free_stack(head), NULL);
		tmp->next = new;
		tmp = tmp->next;
	}
	free(args);
	return (head);
}
