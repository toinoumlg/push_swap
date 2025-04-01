/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:44:06 by amalangu          #+#    #+#             */
/*   Updated: 2025/04/01 17:09:36 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libftprintf/include/ft_printf.h"

# ifndef FT_PRINTF_COLORS
#  define RESET "\x1B[0m"
#  define RED "\x1B[31m"
#  define GREEN "\x1B[32m"
#  define YELLOW "\x1B[33m"
#  define BLUE "\x1B[34m"
#  define MAGENTA "\x1B[35m"
#  define CYAN "\x1B[36m"
#  define WHITE "\x1B[37m"
# endif

typedef struct s_stack
{
	int				i;
	int				index;
	struct s_stack	*next;
}					t_stack;

int					check_arg(char **av, int ac);
int					set_up_args(char **av, int ac, long **args);

void				set_index(t_stack **head, long *args, int size);
int					head_index(t_stack *stack);
int					next_index(t_stack *stack);
int					tail_index(t_stack *stack);
int					tail_previous_index(t_stack *stack);
int					head_next_index(t_stack *stack);

t_stack				*set_stack(char **av, int ac);
int					stack_size(t_stack *stack);
void				free_stack(t_stack *stack);
int					is_stack_sorted(t_stack *stack);

void				push_a(t_stack **a, t_stack **b);
void				push_b(t_stack **a, t_stack **b);

void				swap(t_stack **stack, char a_or_b);
void				ss(t_stack **a, t_stack **b);

void				rotate(t_stack **stack, char a_or_b);
void				rr(t_stack **a, t_stack **b);
void				reverse_rotate(t_stack **stack, char a_or_b);
void				rrr(t_stack **a, t_stack **b);

void				radx(t_stack **a, t_stack **b, int size);
void				sort_small(t_stack **a, t_stack **b, int size);
void				print_stacks(t_stack *a, t_stack *b);

#endif