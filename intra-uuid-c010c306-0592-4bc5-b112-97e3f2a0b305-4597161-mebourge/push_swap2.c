/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:09:29 by mebourge          #+#    #+#             */
/*   Updated: 2022/12/15 15:36:59 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_estimate(long n)
{
	size_t	estim;
	int		isneg;

	estim = 0;
	isneg = 0;
	if (n < 0)
	{
		estim++;
		isneg++;
		n = -n;
	}
	while (n >= 1)
	{
		estim++;
		n /= 10;
	}
	return (estim);
}

void	ft_verif_if_overflow(int argc, char **argv)
{
	int		i;
	long	value;
	int		len;

	i = 1;
	while (i != argc)
	{
		if (ft_atoi(argv[i]) != 0)
		{
			len = ft_strlen(argv[i]);
			value = ft_estimate(ft_atoi(argv[i]));
			if (len != value)
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}
