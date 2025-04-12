/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:37:24 by jankruchina       #+#    #+#             */
/*   Updated: 2025/02/23 12:04:35 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // EXIT_SUCCES
#include <stdio.h> // printf()
#include <unistd.h> // getpid()
#include <signal.h> // signal

static int	binary_position;
static char	character;

void	process_char1(int binary_position)
{
	if (binary_position == 1)
	{
		// write(1, "1\n", 2);
		character += 64;
		// printf("%d\n", character);
	}
	else if (binary_position == 2)
	{
		// write(1, "2\n", 2);
		character += 32;
		// printf("%d\n", character);
	}
	else if (binary_position == 3)
	{
		// write(1, "3\n", 2);
		character += 16;
		// printf("%d\n", character);
	}
	else if (binary_position == 4)
	{
		// write(1, "4\n", 2);
		character += 8;
		// printf("%d\n", character);
	}
	else if (binary_position == 5)
	{
		// write(1, "5\n", 2);
		character += 4;
		// printf("%d\n", character);
	}
	else if (binary_position == 6)
	{
		// write(1, "6\n", 2);
		character += 2;
		// printf("%d\n", character);
	}
	else if (binary_position == 7)
	{
		// write(1, "7\n", 2);
		character += 1;
		// printf("%d\n", character);
		// write(1, "\n", 1);
		write(1, &character, 1);
		// write(1, "\n", 1);
		character = 0;
		binary_position = 1;
	}
}

void	process_char0(int binary_position)
{
	// static char	character;
	if (binary_position == 7)
	{
		// printf("%d\n", character);
		// write(1, "\n", 1);
		write(1, &character, 1);
		// write(1, "\n", 1);
		character = 0;
	}
	// else
	// {
	// 	// printf("%d\n", character);
	// 	// char bin = binary_position + 48;
	// 	// write(1, &bin, 1);
	// 	// write(1, "\n", 1);
	// }
}

void	signal_handler1(int signum)
{
	process_char1(binary_position);
	if (binary_position == 7)
		binary_position = 1;
	else
		binary_position++;
	// write(1, "1", 1);
	(void)signum;
}

void	signal_handler2(int signum)
{
	// printf("%d\n", binary_position);
	process_char0(binary_position);
	if (binary_position == 7)
		binary_position = 1;
	else
		binary_position++;
	// write(1, "0", 1);
	(void)signum;
}

int	main(void)
{
	printf("server PID: %d\n", getpid());
	binary_position = 1;
	character = 0;
	signal(SIGUSR1, signal_handler1);
	signal(SIGUSR2, signal_handler2);
	while (1)
		sleep(1);
	return (EXIT_SUCCESS);
}
