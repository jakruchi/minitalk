#include <signal.h> // signal
#include <stdio.h>	// printf
#include <stdlib.h> // exit, malloc, free
#include <unistd.h> // sleep
#include <strings.h> // bzero
#include <string.h> // memset

unsigned char	*g_buffer = NULL;

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	handle_shutdown(int signum)
{
	// if (g_buffer)
		// free(g_buffer);
	printf("\nServer is shutting down. Signal: %d. Bye bye.\n", signum); // printf
	exit (EXIT_SUCCESS);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	handle_str_signals(int signum, size_t *strlen, int *signal_count)
{
	static int		i;

	if (signum == 10)
		g_buffer[*strlen] >>= 1;
	else
	{
		g_buffer[*strlen] >>= 1;
		g_buffer[*strlen] ^= 0x80;
	}
	i++;
	if (i > 7)
	{
		i = 0;
		*strlen += 1;
		if (g_buffer[*strlen - 1] == '\0')
		{
			printf("%s\n", g_buffer); // ft_printf
			// ft_bzero(g_buffer, *strlen +1);
			memset(g_buffer, 0, *strlen + 1); // ft_memset nefunguje!!!!
			free(g_buffer);
			g_buffer = NULL;
			*strlen = 0;
			*signal_count = 0;
		}
	}
}

static void	handle_signals(int signum, siginfo_t *info, void *context)
{
	(void)context;

	kill(info->si_pid, signum);
}

int	main(void)
{
	struct sigaction minitalk;

	minitalk.sa_sigaction = handle_signals;
	minitalk.sa_flags = SA_SIGINFO;
	sigemptyset(&minitalk.sa_mask);
	sigaction(SIGUSR1, &minitalk, NULL);
	sigaction(SIGUSR2, &minitalk, NULL);
	signal(SIGINT, handle_shutdown);
	signal(SIGTERM, handle_shutdown);
	printf("%d\n", getpid()); // ft_printf
	pause();
	return (0);
}

