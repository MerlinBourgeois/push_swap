/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlinbourgeois <merlinbourgeois@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:41:54 by mebourge          #+#    #+#             */
/*   Updated: 2022/12/11 17:07:48 by merlinbourg      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_push_swap *stack)
{
	int	i;
	int	j;

	j = 0;
	if (stack->size_a <= 5)
		ft_arcodage3(stack);
	ft_put_long_indic(stack);
	while (ft_verif_if_complete(stack) == 1)
	{
		i = stack->size_a;
		while (i--)
		{
			if ((((int)(*stack->stack_a >> (j + 32))) & 1) == 0)
				ft_pb(stack);
			else
			{
				ft_ra(stack);
			}
		}
		j++;
		while (stack->size_b)
			ft_pa(stack);
	}
}

void	ft_put_long_indic(t_push_swap *stack)
{
	int	i;
	int	j;
	int	min_i;
	int	min;

	min_i = 0;
	i = 1;
	while (i < stack->size_a + 1)
	{
		min = INT_MAX;
		j = 0;
		while (j < stack->size_a)
		{
			if ((int)stack->stack_a[j] < min
				&& (int)(stack->stack_a[j] >> 32) == 0)
			{
				min = (int)stack->stack_a[j];
				min_i = j;
			}
			++j;
		}
		stack->stack_a[min_i] |= (long)i << 32;
		++i;
	}
}

void	ft_arcodage(t_push_swap *stack)
{
	if ((int)stack->stack_a[0] > (int)stack->stack_a[1]
		&& (int)stack->stack_a[1] > (int)stack->stack_a[2])
	{
		ft_ra(stack);
		ft_sa(stack);
	}
	if ((int)stack->stack_a[0] < (int)stack->stack_a[1]
		&& (int)stack->stack_a[1] > (int)stack->stack_a[2]
		&& (int)stack->stack_a[0] > (int)stack->stack_a[2])
		ft_rra(stack);
	if ((int)stack->stack_a[0] < (int)stack->stack_a[1]
		&& (int)stack->stack_a[1] > (int)stack->stack_a[2]
		&& (int)stack->stack_a[0] < (int)stack->stack_a[2])
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	if ((int)stack->stack_a[0] > (int)stack->stack_a[1]
		&& (int)stack->stack_a[1] < (int)stack->stack_a[2]
		&& (int)stack->stack_a[0] > (int)stack->stack_a[2])
		ft_ra(stack);
	if ((int)stack->stack_a[0] > (int)stack->stack_a[1]
		&& (int)stack->stack_a[1] < (int)stack->stack_a[2]
		&& (int)stack->stack_a[0] < (int)stack->stack_a[2])
		ft_sa(stack);
}

void	ft_arcodage2(t_push_swap *stack, int min, int max)
{
	while (stack->size_a > 3)
	{
		if ((int)(*stack->stack_a) == min || (int)(*stack->stack_a) == max)
			ft_pb(stack);
		else
		{
			ft_ra(stack);
		}
	}
	if ((int)*stack->stack_b > (int)*(stack->stack_b + 1))
		ft_sb(stack);
	if (ft_verif_if_complete(stack) == 1)
		ft_arcodage(stack);
	ft_pa(stack);
	if ((int)*stack->stack_a > (int)*(stack->stack_a + 1)
		|| (int)*stack->stack_b > (int)*stack->stack_a)
	{
		ft_pa(stack);
		ft_ra(stack);
	}
}

void	ft_arcodage3(t_push_swap *stack)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = INT_MAX;
	max = INT_MIN;
	if (ft_verif_if_complete(stack) == 0)
		return ;
	while (i < stack->size_a)
	{
		if ((int)(stack->stack_a[i]) > max)
			max = (int)stack->stack_a[i];
		if ((int)(stack->stack_a[i]) < min)
			min = (int)stack->stack_a[i];
		++i;
	}
	ft_arcodage2(stack, min, max);
	return ;
}
