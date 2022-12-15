/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:41:35 by mebourge          #+#    #+#             */
/*   Updated: 2022/12/11 16:42:32 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_push_swap *stack)
{
	long	tmp;

	if (stack->size_a < 2)
		return ;
	tmp = stack->stack_a[1];
	stack->stack_a[1] = stack->stack_a[0];
	stack->stack_a[0] = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_push_swap *stack)
{
	long	tmp;

	if (stack->size_b < 2)
		return ;
	tmp = stack->stack_b[1];
	stack->stack_b[1] = stack->stack_b[0];
	stack->stack_b[0] = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_push_swap *stack)
{
	ft_sb(stack);
	ft_sa(stack);
	ft_putstr_fd("ss\n", 1);
}

void	ft_pa(t_push_swap *stack)
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
	stack->size_b--;
	stack->size_a++;
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_push_swap *stack)
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
	stack->size_a--;
	stack->size_b++;
	ft_putstr_fd("pb\n", 1);
}
