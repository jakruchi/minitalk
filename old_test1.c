/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_test1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:32:07 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/22 08:49:29 by jankruchina      ###   ########.fr       */
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

	result = (char *)malloc(33 * sizeof(char));
	if (result == NULL)
	{
		exit(1);
	}
	i = 31;
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
	result[32] = '\0';
	return (&result[0]);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("wrong number of arguments, you looser\n");
		return (1);
	}
	int	a = ft_atoi(argv[1]);
	int	b = ft_atoi(argv[2]);
	// printf("a: %d\n", a);
	// printf("b: %d\n", b);
	char	*binary_a = int_to_binary(a);
	char	*binary_b = int_to_binary(b);
	printf("-------------------a & b-------------------\n");
	printf("%s: %d\n", binary_a, a);
	printf("%s: %d\n", binary_b, b);
	int	c = a & b;
	// printf("a & b: %d\n", c);
	char	*binary_c = int_to_binary(c);
	printf("%s: %d\n", binary_c, c);
	printf("-------------------a | b-------------------\n");
	printf("%s: %d\n", binary_a, a);
	printf("%s: %d\n", binary_b, b);
	int	d = a | b;
	char	*binary_d = int_to_binary(d);
	printf("%s: %d\n", binary_d, d);
	printf("-------------------a ^ b-------------------\n");
	printf("%s: %d\n", binary_a, a);
	printf("%s: %d\n", binary_b, b);
	int	e = a ^ b;
	char	*binary_e = int_to_binary(e);
	printf("%s: %d\n", binary_e, e);
	printf("-------------------a >> 1-------------------\n");
	printf("%s: %d\n", binary_a, a);
	int	f = a >> 1;
	char	*binary_f = int_to_binary(f);
	printf("%s: %d\n", binary_f, f);
	printf("-------------------b << 3-------------------\n");
	printf("%s: %d\n", binary_b, b);
	int	g = b << 3;
	char	*binary_g = int_to_binary(g);
	printf("%s: %d\n", binary_g, g);
	printf("-------------------b >> 5-------------------\n");
	printf("%s: %d\n", binary_b, b);
	int	h = b >> 5;
	char	*binary_h = int_to_binary(h);
	printf("%s: %d\n", binary_h, h);
	printf("------------------- ~a -------------------\n");
	printf("%s: %d\n", binary_a, a);
	int	i = ~a;
	char	*binary_i = int_to_binary(i);
	printf("%s: %d\n", binary_i, i);
	printf("------------------- ~b -------------------\n");
	printf("%s: %d\n", binary_b, b);
	int	j = ~b;
	char	*binary_j = int_to_binary(j);
	printf("%s: %d\n", binary_j, j);
	printf("-------------------a = a ^ b-------------------\n");
	printf("%s: %d\n", binary_a, a);
	printf("%s: %d\n", binary_b, b);
	a = a ^ b;
	binary_a = int_to_binary(a);
	printf("%s: %d\n", binary_a, a);
	printf("-------------------b = a ^ b-------------------\n");
	printf("%s: %d\n", binary_a, a);
	printf("%s: %d\n", binary_b, b);
	b = a ^ b;
	binary_b = int_to_binary(b);
	printf("%s: %d\n", binary_b, b);
	printf("-------------------a = a ^ b-------------------\n");
	printf("%s: %d\n", binary_a, a);
	printf("%s: %d\n", binary_b, b);
	a = a ^ b;
	binary_a = int_to_binary(a);
	printf("%s: %d\n", binary_a, a);
	return (0);
}
