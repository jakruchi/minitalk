/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:58:12 by jankruchina       #+#    #+#             */
/*   Updated: 2025/02/17 20:47:38 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int	string_to_int(char *str)
{
	int	number;

	number = 0;
	while (*str != '\0')
	{
		number *= 10;
		number += *str - '0';
		str++;
	}
	return (number);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 2)
	{
		printf("incorrect number of args\n");
		return (EXIT_FAILURE);
	}
	pid = (pid_t)string_to_int(argv[1]);
	// printf("entered PID: %d\n", pid);
	kill(pid, SIGUSR1);
	return (EXIT_SUCCESS);
}
