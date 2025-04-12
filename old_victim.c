/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:36:20 by jankruchina       #+#    #+#             */
/*   Updated: 2025/02/16 19:49:48 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void	signal_handler1(int signum)
{
	printf("SIGINT was received. signum: %d\n", signum);
	exit(EXIT_SUCCESS);
}

void	signal_handler2(int signum)
{
	printf("SIGTERM was received. signum: %d\n", signum);
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	printf("PID: %u\n", getpid()); // ft_printf
	signal(SIGINT, signal_handler1); // ^C
	signal(SIGTERM, signal_handler2); // kill <PID>

	while (1)
	{
		sleep(1);
	}
	return (EXIT_SUCCESS);
}
