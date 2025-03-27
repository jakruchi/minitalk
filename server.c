/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:10:27 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/27 10:57:38 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h> // signal
#include <stdio.h>	// printf
#include <stdlib.h> // exit, malloc, free
#include <unistd.h> // sleep
#include <strings.h> // bzero
#include <string.h> // memset

unsigned char	*g_buffer = NULL;

static void	handle_shutdown(int signum)
{
	free(g_buffer);
	g_buffer = NULL;
	printf("\nServer is shutting down. Signal: %d. Bye bye.\n", signum); // printf
	exit (EXIT_SUCCESS);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

static void	handle_str_signals(int signum, size_t *strlen, int *signal_count)
{
	static int		i;

	g_buffer[*strlen] >>= 1;
	if (signum == 12)
		g_buffer[*strlen] ^= 0x80;
	i++;
	if (i > 7)
	{
		i = 0;
		*strlen += 1;
		if (g_buffer[*strlen - 1] == '\0') // maybe *strlen - 0
		{
			printf("%s\n", g_buffer); // ft_printf
			ft_bzero(g_buffer, *strlen);
			free(g_buffer);
			g_buffer = NULL;
			*strlen = 0;
			*signal_count = 0;
		}
	}
}

static void	handle_signals(int signum)
{
	static int	signal_count;
	static size_t	strlen;

	signal_count++;
	if (signal_count >= 65)
		handle_str_signals(signum, &strlen, &signal_count);
	else
	{
		strlen >>= 1;
		if (signum == 12)
			strlen ^= 0x8000000000000000;
		if (signal_count == 64)
		{
			g_buffer = (unsigned char *)malloc(strlen + 1);
			if (g_buffer == NULL)
				exit(1);
			ft_bzero(g_buffer, strlen);
			strlen = 0;
		}
	}
}

int	main(void)
{
	struct sigaction minitalk;

	minitalk.sa_handler = handle_signals;
	minitalk.sa_flags = 0;
	sigemptyset(&minitalk.sa_mask);
	sigaction(SIGUSR1, &minitalk, NULL);
	sigaction(SIGUSR2, &minitalk, NULL);
	signal(SIGINT, handle_shutdown);
	signal(SIGTERM, handle_shutdown);
	printf("%d\n", getpid()); // ft_printf
	while (1)
		sleep(1);
	return (0);
}
