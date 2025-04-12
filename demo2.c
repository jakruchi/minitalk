/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:32:15 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/24 14:34:41 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h> // signal
#include <stdio.h>	// printf
#include <stdlib.h> // exit, malloc, free
#include <unistd.h> // sleep
#include <strings.h> // bzero
#include <string.h> // memset

int	main(void)
{
	unsigned char	buffer[] = "hello world\n";
	printf("%s", buffer);
	return (0);
}
