/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:41:43 by mebourge          #+#    #+#             */
/*   Updated: 2022/12/11 16:43:17 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_push_swap *stack)
{
	long	i;

	if (stack->size_a == 0)
		return ;
	i = -1;
	stack->tmp = stack->stack_a[0];
	if (stack->size_a > 1)
	{
		while (i++ != stack->size_a - 1)
			stack->stack_a[i] = stack->stack_a[i + 1];
	}
	stack->stack_a[stack->size_a - 1] = stack->tmp;
	if (stack->param_ver == 0)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_push_swap *stack)
{
	long	i;

	if (stack->size_b == 0)
		return ;
	i = -1;
	stack->tmp = stack->stack_b[0];
	if (stack->size_b > 1)
	{
		while (i++ != stack->size_b - 1)
			stack->stack_b[i] = stack->stack_b[i + 1];
	}
	stack->stack_b[stack->size_b - 1] = stack->tmp;
	if (stack->param_ver == 0)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_push_swap *stack)
{
	stack->param_ver = 1;
	ft_rb(stack);
	ft_ra(stack);
	stack->param_ver = 0;
	ft_putstr_fd("rr\n", 1);
}

void	ft_rra(t_push_swap *stack)
{
	long	i;

	stack->tmp = stack->stack_a[stack->size_a - 1];
	i = stack->size_a;
	if (i > 0)
	{
		while (i != 0)
		{
			stack->stack_a[i] = stack->stack_a[i - 1];
			i--;
		}
	}
	stack->stack_a[0] = stack->tmp;
	if (stack->param_ver == 0)
		ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_push_swap *stack)
{
	long	i;

	stack->tmp = stack->stack_b[stack->size_b - 1];
	i = stack->size_b;
	if (i > 0)
	{
		while (i != 0)
		{
			stack->stack_b[i] = stack->stack_b[i - 1];
			i--;
		}
	}
	stack->stack_b[0] = stack->tmp;
	if (stack->param_ver == 0)
		ft_putstr_fd("rrb\n", 1);
}
