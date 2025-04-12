/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:15:30 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/24 14:27:58 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h> // signal
#include <stdio.h>	// printf
#include <stdlib.h> // exit, malloc, free
#include <unistd.h> // sleep
#include <strings.h> // bzero
#include <string.h> // memset

void	char_to_binary(char c)
{
	char	*result;
	int		i;

	result = (char *)malloc(9 * sizeof(char));
	if (result == NULL)
	{
		exit(1);
	}
	i = 7;
	while (i >= 0)
	{
		if ((c % 2) == 1)
		{
			result[i] = '1';
		}
		else
			result[i] = '0';
		c = c >> 1;
		i--;
	}
	result[9] = '\0';
	printf("%s\n", result);
	free(result);
}

int	main(void)
{
	char	character = '\0';
	char_to_binary(character);
	char_to_binary(1);
	char	smth = 1;
	char_to_binary(smth);
	smth = smth << 6;
	char_to_binary(smth);
	smth = smth << 1;
	char_to_binary(smth);
	return (0);
}
