/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:42:57 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/28 15:50:32 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

int	main(void)
{
	// printf("long long int:\n%lu bytes\n%lu-bit\n", sizeof(long long int), sizeof(long long int) * 8);
	// printf("%d 		= int max\n", INT_MAX);
	printf("%u 		= unsigned int max\n", UINT_MAX);
	// printf("%zu 	= ssize_t max\n", SSIZE_MAX);
	// printf("%ld 	= long max\n", LONG_MAX);
	// printf("%lld 	= long long max\n", LLONG_MAX);
	// printf("%lu 	= unsigned long max\n", ULONG_MAX);
	// printf("%llu 	= unsigned long long max\n", ULLONG_MAX);
	return (0);
}
