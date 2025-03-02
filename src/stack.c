/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:30:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/02 19:44:48 by amalangu         ###   ########.fr       */
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

int	check_arg(char *arg)
{
	int	i;
	int	arg_size;

	arg_size = 1;
	i = 0;
	if (!arg)
		return (-1);
	while (arg[i])
	{
		if (arg[i] >= 48 && arg[i] <= 57)
			i++;
		else if ((arg[i - 1] >= 48 && arg[i - 1] <= 57) && arg[i] == 32)
		{
			arg_size++;
			i++;
		}
		else
			return (-1);
	}
	return (arg_size);
}

t_stack	*set_stack(char *arg)
{
	t_stack	*new;
	t_stack	*head;
	t_stack	*tmp;
	int		i;
	int		arg_size;

	i = 0;
	arg_size = check_arg(arg);
	ft_printf("%d\n", arg_size);
	if (arg_size < 0)
		return (NULL);
	head = ft_calloc(sizeof(t_stack), 1);
	if (!head)
		return (NULL);
	head->i = i;
	head->next = NULL;
	tmp = head;
	while (i++ < 10)
	{
		new = ft_calloc(sizeof(t_stack), 1);
		if (!new)
			return (free_stack(head), NULL);
		new->i = i;
		new->next = NULL;
		tmp->next = new;
		tmp = tmp->next;
	}
	return (head);
}

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

void	print_stack(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("%d\n", tmp->i);
		tmp = tmp->next;
	}
}