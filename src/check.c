/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:55:38 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/28 21:17:51 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_and_reset_tmp(char *tmp, long *args, int *x)
{
	long	nb;

	nb = ft_atol(tmp);
	if (nb <= INT_MAX && nb >= INT_MIN)
		args[++*x] = nb;
	else
		return (-1);
	ft_bzero(tmp, 16);
	return (0);
}

int	fill_args_string(char *av, long *args, int i, int j)
{
	char	tmp[16];
	int		x;

	x = -1;
	ft_bzero(tmp, 16);
	while (av[i])
	{
		j = 0;
		if (av[i] == '-' || av[i] == '+')
			tmp[j++] = av[i++];
		while (av[i] >= 48 && av[i] <= 57)
			tmp[j++] = av[i++];
		if (j > 0 && (av[i] == ' ' || av[i] == 0))
			if (check_and_reset_tmp(tmp, args, &x))
				return (-1);
		if (av[i] == ' ')
			i++;
	}
	return (0);
}

int	fill_args(char **av, long *args, int ac)
{
	int		i;
	long	nb;

	i = 0;
	if (ac > 2)
	{
		while (av[++i])
		{
			nb = atol(av[i]);
			if (nb <= INT_MAX && nb >= INT_MIN)
				args[i - 1] = nb;
			else
				return (-1);
		}
	}
	if (ac == 2)
		if (fill_args_string(av[1], args, 0, 0))
			return (-1);
	return (0);
}

int	duplicate(long *args, int size)
{
	int	i;
	int	x;

	i = -1;
	while (++i < size)
	{
		x = i;
		while (++x < size)
			if (args[i] == args[x])
				return (-1);
	}
	return (0);
}

int	set_up_args(char **av, int ac, long **args)
{
	int	size;

	size = check_arg(av, ac);
	if (size < 1)
		return (ft_printf("Error\n"), -1);
	else
		*args = ft_calloc(sizeof(long), size + 1);
	if (!*args)
		return (-1);
	if (fill_args(av, *args, ac))
		return (ft_printf("Error\n"), free(*args), -1);
	if (duplicate(*args, size))
		return (ft_printf("Error\n"),
			free(*args), -1);
	return (size);
}
