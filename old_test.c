/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:15:24 by jankruchina       #+#    #+#             */
/*   Updated: 2025/02/22 19:38:14 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // printf

int	main(void)
{
	int character = 97;

	// printf("character: %d\n", character);
	printf("0");
	if ((character / 64) >= 1)
	{
		printf("1");
		character -= 64;
	}
	else
		printf("0");
	// printf("\ncharacter: %d\n", character);
	if ((character / 32) >= 1)
	{
		printf("1");
		character -= 32;
	}
	else
		printf("0");
	// printf("\ncharacter: %d\n", character);
	if ((character / 16) >= 1)
	{
		printf("1");
		character -= 16;
	}
	else
		printf("0");
	// printf("\ncharacter: %d\n", character);
	if ((character / 8) >= 1)
	{
		printf("1");
		character -= 8;
	}
	else
		printf("0");
	// printf("\ncharacter: %d\n", character);
	if ((character / 4) >= 1)
	{
		printf("1");
		character -= 4;
	}
	else
		printf("0");
	// printf("\ncharacter: %d\n", character);
	if ((character / 2) >= 1)
	{
		printf("1");
		character -= 2;
	}
	else
		printf("0");
	// printf("\ncharacter: %d\n", character);
	if ((character / 1) >= 1)
	{
		printf("1");
		character -= 1;
	}
	else
		printf("0");
	// printf("\ncharacter: %d\n", character);
	return (0);
}

// printf("97 %% 127: %d\n", (127 % 97));
	// printf("97 %% 63: %d\n",  (63  % 97));
	// printf("97 %% 31: %d\n",  (31  % 97));
	// printf("97 %% 15: %d\n",  (15  % 97));
	// printf("97 %% 7: %d\n",   (7   % 97));
	// printf("97 %% 3: %d\n",   (3   % 97));
	// printf("97 %% 1: %d\n",   (1   % 97));

