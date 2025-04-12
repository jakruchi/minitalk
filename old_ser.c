/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ser.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:29:02 by jankruchina       #+#    #+#             */
/*   Updated: 2025/02/23 16:00:23 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h> // signal()
#include <stdio.h> // printf()
#include <unistd.h> // getpid()

void	signal_handler1(int signum)
{
	printf("%d\n", signum);
}

void	signal_handler2(int signum)
{
	printf("%d\n", signum);
}

int	main(void)
{
	printf("%d\n", getpid());
	signal(SIGUSR1, signal_handler1);
	signal(SIGUSR2, signal_handler2);
	while (1)
		sleep(1);
	return (0);
}
