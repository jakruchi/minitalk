/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:10:27 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/28 23:45:11 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_data	*g_data;

static void	reset_data(void)
{
	g_data->buffer = NULL;
	g_data->bit_position = 0;
	g_data->pid = 0;
	g_data->signal_count = 0;
	g_data->strlen = 0;
}

static void	handle_shutdown(int signum)
{
	(void)signum;
	if (g_data->buffer == NULL)
	{
		free(g_data);
		write(1, "\nServer is shutting down. Bye bye.\n", 35);
		exit (EXIT_SUCCESS);
	}
	else
	{
		free(g_data->buffer);
		free(g_data);
		write(1, "\nIncomplete message: Buffer was not empty. Bye bye.\n", 52);
		exit (EXIT_FAILURE);
	}
}

static void	handle_str_signals(int signum)
{
	g_data->buffer[g_data->strlen] >>= 1;
	if (signum == 12)
		g_data->buffer[g_data->strlen] ^= 0x80;
	g_data->bit_position++;
	if (g_data->bit_position > 7)
	{
		g_data->bit_position = 0;
		g_data->strlen += 1;
		if (g_data->buffer[g_data->strlen - 1] == '\0')
		{
			write(1, g_data->buffer, g_data->strlen);
			write(1, "\n", 1);
			ft_bzero(g_data->buffer, g_data->strlen);
			free(g_data->buffer);
			g_data->buffer = NULL;
			g_data->strlen = 0;
			g_data->signal_count = 0;
		}
	}
}

static void	handle_signals(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (g_data->pid != info->si_pid)
	{
		free(g_data->buffer);
		reset_data();
		g_data->pid = info->si_pid;
	}
	g_data->signal_count++;
	if (g_data->signal_count >= 33)
		handle_str_signals(signum);
	else
	{
		g_data->strlen >>= 1;
		if (signum == 12)
			g_data->strlen ^= 0x80000000;
		if (g_data->signal_count == 32)
		{
			g_data->buffer = (unsigned char *)malloc(g_data->strlen + 1);
			if (g_data->buffer == NULL)
				exit(1);
			ft_bzero(g_data->buffer, g_data->strlen);
			g_data->strlen = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	minitalk;

	g_data = (t_data *)malloc(sizeof(t_data));
	if (g_data == NULL)
		return (1);
	reset_data();
	minitalk.sa_sigaction = handle_signals;
	minitalk.sa_flags = SA_SIGINFO;
	sigemptyset(&minitalk.sa_mask);
	sigaction(SIGUSR1, &minitalk, NULL);
	sigaction(SIGUSR2, &minitalk, NULL);
	signal(SIGINT, handle_shutdown);
	signal(SIGTERM, handle_shutdown);
	write(1, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
