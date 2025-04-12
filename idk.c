/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:05:27 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/28 21:57:34 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd,"-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		write(fd, &(char){n + '0'}, 1);
}

int	main()
{
	// ft_putnbr_fd(54323, 1);
	// write(1, "\n", 1);

	// int	a = 30;
	// a += (int){15};
	// a += 15;
	// printf("%d", a);
	char *ahoj;

	ahoj = "ahojky ty pico";
	printf("%s", ahoj);
	return (0);
}
