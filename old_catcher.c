/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:58:28 by jankruchina       #+#    #+#             */
/*   Updated: 2025/02/17 20:45:49 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

void	signal_handler(int signum)
{
	printf("i got the signal: %d\n", signum);
}

int	main(void)
{
	struct sigaction	action;
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);

	printf("PID: %u\n", getpid()); // ft_printf
	while (1)
		sleep(1);
	return (EXIT_SUCCESS);
}
