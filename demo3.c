/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:25:36 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/24 18:26:44 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	// printf
#include <signal.h> // kill
#include <unistd.h> // pause
#include <stdlib.h> // malloc, exit, free

int	main()
{
	pid_t number = (int)-3232;
	printf("%d\n", number);
	return (0);
}
