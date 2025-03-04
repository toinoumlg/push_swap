/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:55:38 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/04 19:33:15 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

int	check_arg(char **av)
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
	return (0);
}

void	fill_args(char **av, int *args)
{
	int	i;

	i = 0;
	while (av[++i])
		args[i - 1] = ft_atoi(av[i]);
}

int	*set_up_args(char **av, int ac)
{
	int	*args;

	if (check_arg(av))
		return (NULL);
	else
		args = ft_calloc(sizeof(int), ac + 1);
	if (!args)
		return (NULL);
	fill_args(av, args);
	return (args);
}
