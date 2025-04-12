/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeptest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:40:35 by jankruchina       #+#    #+#             */
/*   Updated: 2025/02/22 11:51:11 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	printf("calling sleep(5)\n");
	usleep(5000000);
	printf("done sleep(5)\n");
	return (EXIT_SUCCESS);
}
