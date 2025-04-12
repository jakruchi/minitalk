#include <signal.h> // signal
#include <stdio.h>	// printf
#include <stdlib.h> // exit, malloc, free
#include <unistd.h> // sleep
#include <strings.h> // bzero
#include <string.h> // memset

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	send_strlen(pid_t pid, size_t strlen)
{
	size_t	i;

	i = 0;
	while (i < (sizeof(strlen) * 8))
	{
		if (strlen & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		strlen >>= 1;
		i++;
		usleep(1000);
	}
}

void	send_str(pid_t pid, char *str, size_t strlen)
{
	size_t	i;
	int	j;

	i = 0;
	while (i <= strlen)
	{
		j = 8;
		while (j)
		{
			if (str[i] & 0x01)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			str[i] >>= 1;
			j--;
			usleep(1000);
		}
		i++;
	}
}

void	myfunc()
{
	write(1, "SIGUSR!", 7);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	signal(SIGUSR1, myfunc);
	if (argc != 3)
	{
		printf("Wrong number of arguments. You dummy.\n"); // ft_printf
		return (1);
	}
	if (argv[2][0] == '\0')
	{
		printf("You are sending an empty string. You dummy.\n"); // ft_printf
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 2)
	{
		printf("PID has to be higher than 1. You dummy.\n"); // ft_printf
		return (1);
	}
	pid = ft_atoi(argv[1]);
	kill(pid, SIGUSR1);
	pause();
	write(1, "i am unpaused.\n", 15);
	return (0);
}

