/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:55:38 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/09 18:29:36 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	fill_args_string(char *av, int *args)
{
	char	*tmp;
	int		i;
	int		j;
	int		x;

	i = 0;
	x = -1;
	tmp = ft_calloc(sizeof(char), 16);
	while (av[i])
	{
		j = -1;
		while (av[i] >= 48 && av[i] <= 57)
		{
			tmp[++j] = av[i];
			i++;
		}
		if ((av[i - 1] >= 48 && av[i - 1] <= 57) && av[i] == 32)
		{
			i++;
			args[++x] = ft_atoi(tmp);
			ft_bzero(tmp, 16);
		}
		if (av[i] == 0 && (av[i - 1] >= 48 && av[i - 1] <= 57))
			return (args[++x] = ft_atoi(tmp), free(tmp));
	}
}

void	fill_args(char **av, int *args, int ac)
{
	int	i;

	i = 0;
	if (ac > 2)
		while (av[++i])
			args[i - 1] = ft_atoi(av[i]);
	if (ac == 2)
		fill_args_string(av[1], args);
}

int	*set_up_args(char **av, int ac)
{
	int	*args;
	int	size;

	size = check_arg(av, ac);
	if (size < 1)
		return (ft_printf("Error\nArguments arent correct"), NULL);
	else
		args = ft_calloc(sizeof(int), size + 1);
	if (!args)
		return (NULL);
	fill_args(av, args, ac);
	return (args);
}
