/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:18:19 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/28 23:18:17 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h> // signal
# include <stdlib.h> // exit, malloc, free
# include <unistd.h> // sleep

typedef struct s_data
{
	unsigned char	*buffer;
	unsigned int	strlen;
	pid_t			pid;
	long long int	signal_count;
	short int		bit_position;
}	t_data;

// server_utils.c
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);

#endif
