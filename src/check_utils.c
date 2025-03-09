/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:14:35 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/09 16:16:27 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_arg_multiple_ac(char **av)
{
	int	i;
	int	j;

	i = 1;
	if (!av)
		return (-1);
	while (av[i])
	{
		j = 0;
		while (av[i][j] >= 48 && av[i][j] <= 57)
			j++;
		if (av[i][j] != 0)
			return (-1);
		else
			i++;
	}
	return (i - 1);
}

int	check_arg_single_ac(char *av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!av)
		return (-1);
	while (av[i])
	{
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
		return (check_arg_multiple_ac(av));
	if (ac == 2)
		return (check_arg_single_ac(av[1]));
	return (-1);
}
