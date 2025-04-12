/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:17:21 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/24 18:20:57 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	// printf
#include <signal.h> // kill
#include <unistd.h> // pause
#include <stdlib.h> // malloc, exit, free

int	ft_atoi(const char *nptr) // static
{
	size_t	i;
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
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

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int number = ft_atoi(argv[1]);
	printf("%d\n", number);
	return (0);
}
