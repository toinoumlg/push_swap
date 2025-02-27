/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:44:06 by amalangu          #+#    #+#             */
/*   Updated: 2025/02/27 18:09:05 by amalangu         ###   ########.fr       */
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

void				free_stack(t_stack *stack);
t_stack				*set_stack(void);
void				print_stack(t_stack *stack);
void				print_stacks(t_stack *a, t_stack *b);

void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);

void	swap(t_stack *stack, char a_or_b);
void	ss(t_stack *a, t_stack *b);

#endif