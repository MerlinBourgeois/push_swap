/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:41:48 by mebourge          #+#    #+#             */
/*   Updated: 2022/12/15 15:16:08 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verif_if_complete(t_push_swap *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i != stack->argc - 2)
	{
		j = i + 1;
		while (j != stack->argc - 1)
		{
			if (stack->stack_a[i] > stack->stack_a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_verif_if_dubble(t_push_swap *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i != stack->argc - 2)
	{
		j = i + 1;
		while (j != stack->argc - 1)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
			{
				ft_putstr_fd("Error\n", 2);
				free(stack->stack_a);
				free(stack->stack_b);
				free(stack);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	ft_init_error_verif(int argc, char **argv)
{
	int	nb_arg;
	int	i;

	nb_arg = 1;
	i = 0;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	while (nb_arg != argc)
	{
		i = 0;
		while (argv[nb_arg][i] != '\0')
		{
			if (ft_isdigit(argv[nb_arg][i]) != 1 && argv[nb_arg][i] != '-')
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_SUCCESS);
			}
			i++;
		}
		nb_arg++;
	}
}

void	ft_main_alloc(t_push_swap *stack, int argc)
{
	if (!stack)
		exit(EXIT_FAILURE);
	stack->stack_a = ft_calloc((argc - 1), sizeof(long));
	if (!stack->stack_a)
	{
		free(stack);
		exit(EXIT_FAILURE);
	}
	stack->stack_b = ft_calloc((argc - 1), sizeof(long));
	if (!stack->stack_b)
	{
		free(stack->stack_a);
		free(stack);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_push_swap	*stack;
	int			nb_arg;

	ft_init_error_verif(argc, argv);
	ft_verif_if_overflow(argc, argv);
	nb_arg = 0;
	stack = malloc(sizeof(t_push_swap));
	ft_main_alloc(stack, argc);
	stack->argc = argc;
	stack->argv = argv;
	stack->size_a = argc - 1;
	stack->size_b = 0;
	while (nb_arg != argc - 1)
	{
		stack->stack_a[nb_arg] = ft_atoi(argv[nb_arg + 1]);
		if (stack->stack_a[nb_arg] < 0)
			stack->stack_a[nb_arg] ^= 0xffffffff00000000;
		nb_arg++;
	}
	ft_verif_if_dubble(stack);
	radix(stack);
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
	exit(EXIT_SUCCESS);
}
