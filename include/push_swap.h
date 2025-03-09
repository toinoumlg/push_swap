/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:44:06 by amalangu          #+#    #+#             */
/*   Updated: 2025/03/09 17:15:47 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libftprintf/include/ft_printf.h"

typedef struct s_stack
{
	int				i;
	struct s_stack	*next;
}					t_stack;

int					check_arg(char **av, int ac);
int					*set_up_args(char **av, int ac);

t_stack				*set_stack(char **av, int ac);
void				free_stack(t_stack *stack);

void				push_a(t_stack **a, t_stack **b);
void				push_b(t_stack **a, t_stack **b);

void				swap(t_stack *stack, char a_or_b);
void				ss(t_stack *a, t_stack *b);

void				rotate(t_stack **stack, char a_or_b);
void				rr(t_stack **a, t_stack **b);
void				reverse_rotate(t_stack **stack, char a_or_b);
void				rrr(t_stack **a, t_stack **b);

void				print_stacks(t_stack *a, t_stack *b);

#endif