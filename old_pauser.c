/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pauser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:56:46 by jankruchina       #+#    #+#             */
/*   Updated: 2025/02/22 12:33:23 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	signal_handlerUSR1(int signum)
{
	printf("I got the SIGUSR1. signum: %d\n", signum);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("pauser is running. PID: %d\n", pid);
	signal(SIGUSR1, signal_handlerUSR1);
	pause();
	printf("server is shutting down.\n");
	return (EXIT_SUCCESS);
}
