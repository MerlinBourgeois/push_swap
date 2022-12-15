/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:41:45 by mebourge          #+#    #+#             */
/*   Updated: 2022/12/11 16:43:29 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_push_swap *stack)
{
	stack->param_ver = 1;
	ft_rrb(stack);
	ft_rra(stack);
	stack->param_ver = 0;
	ft_putstr_fd("rrr\n", 1);
}
