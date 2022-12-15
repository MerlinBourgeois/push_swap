/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:41:51 by mebourge          #+#    #+#             */
/*   Updated: 2022/12/15 15:35:53 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "includes/libft/libft.h"

typedef struct s_push_swap
{
	long	*stack_a;
	long	*stack_b;
	int		argc;
	char	**argv;
	int		size_a;
	int		size_b;
	long	tmp;
	int		param_ver;
}	t_push_swap;

void		ft_sa(t_push_swap *stack);
void		ft_sb(t_push_swap *stack);
void		ft_pa(t_push_swap *stack);
void		ft_pb(t_push_swap *stack);
void		ft_ss(t_push_swap *stack);
void		ft_ra(t_push_swap *stack);
void		ft_rb(t_push_swap *stack);
void		ft_rr(t_push_swap *stack);
void		ft_rra(t_push_swap *stack);
void		ft_rrb(t_push_swap *stack);
void		ft_rrr(t_push_swap *stack);
void		ft_print_stack(t_push_swap *stack);
int			ft_verif_if_complete(t_push_swap *stack);
void		radix(t_push_swap *stack);
void		ft_put_long_indic(t_push_swap *stack);
void		ft_arcodage(t_push_swap *stack);
void		ft_arcodage3(t_push_swap *stack);
void		ft_arcodage2(t_push_swap *stack, int min, int max);
void		ft_arcodage(t_push_swap *stack);
void		ft_verif_if_overflow(int argc, char **argv);

#endif