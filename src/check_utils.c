/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:14:35 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/23 11:31:46 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_arg_multiple_ac(char **av, int i, int j)
{
	if (!av)
		return (-1);
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' || '+')
			j++;
		while (av[i][j] >= 48 && av[i][j] <= 57)
			j++;
		if (av[i][j] != 0)
			return (-1);
		else
			i++;
	}
	return (i - 1);
}

int	check_arg_single_ac(char *av, int i, int j)
{
	if (!av)
		return (-1);
	while (av[i])
	{
		if (av[i] == '-' || av[i] == '+')
			i++;
		while (av[i] >= 48 && av[i] <= 57)
			i++;
		if (!av[i])
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
		return (check_arg_multiple_ac(av, 1, 0));
	if (ac == 2)
		return (check_arg_single_ac(av[1], 0, 0));
	return (-1);
}
