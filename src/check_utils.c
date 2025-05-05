/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:14:35 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/05 15:21:32 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_arg_multiple_ac(char **av, int i, int j, int ac)
{
	int	count;

	count = 0;
	if (!av)
		return (-1);
	while (++i < ac && av[i])
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (i < ac && av[i][j] == 0)
			i++;
		if (i >= ac)
			return (count);
		while (av[i][j] >= 48 && av[i][j] <= 57)
			j++;
		if (av[i][j] != 0)
			return (-1);
		else
			count++;
	}
	return (count);
}

int	check_arg_single_ac(char *av, int i, int j)
{
	int	op;

	op = 0;
	if (!av)
		return (-1);
	while (av[i])
	{
		if ((av[i] == '-' || av[i] == '+') && ++op)
			i++;
		while (av[i] >= 48 && av[i] <= 57)
			i++;
		if (!av[i] && i - op > 0)
		{
			j++;
			break ;
		}
		if ((av[i - 1] >= 48 && av[i - 1] <= 57) && (av[i] == 32))
		{
			i++;
			j++;
		}
		else
			return (-1);
	}
	return (j);
}

int	check_arg(char **av, int ac)
{
	if (ac > 2)
		return (check_arg_multiple_ac(av, 0, 0, ac));
	if (ac == 2)
		return (check_arg_single_ac(av[1], 0, 0));
	return (-1);
}
