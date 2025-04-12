/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_intPTR_to_charPTR.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:00:00 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/23 12:42:38 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // printf
#include <stdlib.h> // malloc

void *ptr;

void	save_int(int num)
{
	ptr = malloc(1 * sizeof(int));
	if (ptr == NULL)
		exit(1);
	*((int *)ptr) = num;
}

void	print_int(void)
{
	printf("%d\n", *((int *)ptr)); // expected outcome: 1200
	free(ptr);
}

void	save_hello(void)
{
	ptr = malloc(6 * sizeof(char));
	if (ptr == NULL)
		exit(1);
	((char *)ptr)[0] = 'H';
	((char *)ptr)[1] = 'e';
	((char *)ptr)[2] = 'l';
	((char *)ptr)[3] = 'l';
	((char *)ptr)[4] = '0';
	((char *)ptr)[5] = '\0';
}

void	print_hello(void)
{
	printf("%s\n", (char *)ptr); // expected outcome: "Hello"
	free(ptr);
}

int	main(void)
{
	save_int(12000);
	print_int();
	save_hello();
	print_hello();
	return (0);
}
