/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_shifter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:32:07 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/22 16:12:55 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // printf()
#include <stdlib.h> // malloc()
#include <limits.h> // INT_MAX

static int	ft_isspace(int c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}

char	*int_to_binary(int c)
{
	char	*result;
	int		i;

	result = (char *)malloc(17 * sizeof(char));
	if (result == NULL)
	{
		exit(1);
	}
	i = 15;
	while (i >= 0)
	{
		if (((c % 2) == 1) || ((c % 2) == -1))
		{
			result[i] = '1';
		}
		else
			result[i] = '0';
		c = c >> 1;
		i--;
	}
	result[17] = '\0';
	return (&result[0]);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("wrong number of arguments, you looser\n");
		return (1);
	}
	unsigned short int	a = (unsigned short int)ft_atoi(argv[1]);
	int	b = ft_atoi(argv[2]);
	// printf("a: %d\n", a);
	// printf("b: %d\n", b);
	char	*binary_a = int_to_binary(a);
	printf("-------------------a << b-------------------\n");
	printf("%s: %d\n", binary_a, a);
	a = a << b;
	binary_a = int_to_binary(a);
	printf("%s: %d\n", binary_a, a);
	return (0);
}
