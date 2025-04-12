// file1.c
#include <stdio.h>

int ft_isspace(int c)  // `static` restricts visibility
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}
