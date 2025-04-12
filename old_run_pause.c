/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_run_pause.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:56:07 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/23 23:58:57 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("%d\n", getpid());
	pause();
	printf("I am unpaused now.\n");
	return (0);
}
