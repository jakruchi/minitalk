/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   janevim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:10:27 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/28 22:46:24 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// unsigned char	*g_buffer = NULL;
t_data			*g_data;

// typedef struct s_data
// {
// 	unsigned char	*buffer;
// 	unsigned int	strlen;
// 	pid_t			pid;
// 	long long int	signal_count;
// 	short int		bit_position;
// }	t_data;

void	reset_data(void)
{
	g_data->buffer = NULL;
	g_data->bit_position = 0;
	g_data->pid = 0;
	g_data->signal_count = 0;
	g_data->strlen = 0;
}

void	handle_shutdown(int signum)
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
		write(1, "\nBuffer was not empty. Server is shutting down in the middle of a message. Bye bye anyway.\n", 91);
		exit (EXIT_FAILURE);
	}
}

void	ft_bzero(void *s, size_t n)
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

void	handle_str_signals(int signum, pid_t pid_client)
{
	// (void)pid_client; // delete this after commenting back in the code below
	if (g_data->pid != pid_client)
	{
		reset_data();
		g_data->pid = pid_client;
		g_data->strlen >>= 1;
		if (signum == 12)
			g_data->strlen ^= 0x80000000; //0x8000000000000000
	}
	g_data->buffer[g_data->strlen] >>= 1;
	if (signum == 12)
		g_data->buffer[g_data->strlen] ^= 0x80;
	g_data->bit_position++;
	if (g_data->bit_position > 7)
	{
		g_data->bit_position = 0;
		g_data->strlen += 1;
		if (g_data->buffer[g_data->strlen - 1] == '\0') // maybe *strlen - 0
		{
			printf("%s\n", g_data->buffer); // ft_printf
			ft_bzero(g_data->buffer, g_data->strlen);
			free(g_data->buffer);
			g_data->buffer = NULL;
			g_data->strlen = 0;
			g_data->signal_count = 0;
		}
	}
}

void	handle_signals(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (g_data->pid != info->si_pid)
	{
		reset_data();
		g_data->pid = info->si_pid;
	}
	g_data->signal_count++;
	if (g_data->signal_count >= 33) // 65
		handle_str_signals(signum, info->si_pid);
	else
	{
		g_data->strlen >>= 1;
		if (signum == 12)
			g_data->strlen ^= 0x80000000; // 0x8000000000000000
		if (g_data->signal_count == 32) //64
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
	// struct sigaction minitalk;

	// g_data = (t_data *)malloc(sizeof(t_data));
	// if (g_data == NULL)
	// 	return (1);
	// reset_data();
	// minitalk.sa_sigaction = handle_signals;
	// minitalk.sa_flags = SA_SIGINFO;
	// sigemptyset(&minitalk.sa_mask);
	// sigaction(SIGUSR1, &minitalk, NULL);
	// sigaction(SIGUSR2, &minitalk, NULL);
	// signal(SIGINT, handle_shutdown);
	// signal(SIGTERM, handle_shutdown);
	printf("Server PID: %d\n", getpid()); // ft_printf
	while (1)
		pause();
	return (0);
}
