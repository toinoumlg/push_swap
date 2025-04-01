/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:30:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/04/01 15:56:08 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack && ++i)
		stack = stack->next;
	return (i);
}

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

// fills stack with arguments
void	set_head(t_stack **head, long *args, int size)
{
	t_stack	*new;
	t_stack	*tmp;
	int		i;

	i = 0;
	*head = new_stack(args[i]);
	tmp = *head;
	while (++i < size)
	{
		new = new_stack(args[i]);
		if (!new)
			return (free_stack(*head));
		tmp->next = new;
		tmp = tmp->next;
	}
}

// return a stack with arguments, NULL if args arent correct
t_stack	*set_stack(char **av, int ac)
{
	t_stack	*head;
	long	*args;
	int		size;

	size = set_up_args(av, ac, &args);
	if (size < 0 || !args)
		return (NULL);
	set_head(&head, args, size);
	if (!head)
		return (free(args), NULL);
	set_index(&head, args, size);
	free(args);
	return (head);
}
