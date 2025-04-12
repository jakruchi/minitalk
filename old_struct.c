/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:06:24 by jankruchina       #+#    #+#             */
/*   Updated: 2025/03/11 20:22:42 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h> // strcpy
#include <stdio.h> // printf

struct s_car
{
	char	brand[10];
	int		year;
};

int	main(void)
{
	struct s_car	fiesta;

	fiesta.year = 2005;
	strcpy(fiesta.brand, "Ford");
	printf("%s from %d\n", fiesta.brand, fiesta.year);
	return (0);
}
