/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:41:32 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/23 13:03:06 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h> // signal
#include <stdio.h>	// printf
#include <stdlib.h> // exit, malloc, free
#include <unistd.h> // sleep

void	int_to_binary(unsigned short int c)
{
	char	*result;
	int		i;

	result = (char *)malloc(17 * sizeof(char));
	if (result == NULL)
	{
		exit(1);
	}
	i = 15;
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
	result[17] = '\0';
	printf("%s\n", result);
	free(result);
}

static unsigned short int str_len;

void	handle_shutdown() // static
{
	// free everything
	printf("\nreceived: %hu\n", str_len);
	// int_to_binary(str_len);
	printf("\nThe server is shutting down.\n");
	exit(EXIT_SUCCESS);
}

void	handle_SIGUSRX(int signum) // static void	handle_comm // 0
{
	static int	count;
	if (signum == 10)
	{
		printf("0");
		str_len >>= 1;
	}
	else
	{
		printf("1");
		str_len >>= 1;
		str_len ^= 32768;
	}
	count++;
	if (count == 16)
	{
		printf("count = 16");
	}
}



int	main(void)
{
	signal(SIGINT, handle_shutdown);
	signal(SIGTERM, handle_shutdown);
	struct sigaction minitalk;
	minitalk.sa_sigaction = handle_SIGUSRX;
	sigemptyset(&minitalk.sa_mask);
	minitalk.sa_flags = ;

	sigaction(SIGUSR1, &minitalk, NULL);
	sigaction(SIGUSR2, &minitalk, NULL);

	printf("%d\n", getpid());
	while (1)
	{
		sleep(1);
	}
	return (0);
}

// 14					// signal_count
// 0100 0000 0000 0000 // str_len
// 1111 1100 0000 0000 // signals received
// 0000 0000 0000 0001 // temp
// 0100 0000 0000 0000 // current temp
// 32768 16384 8192 4096	2048 1024 512 256	128 64 32 16	8 4 2 1
