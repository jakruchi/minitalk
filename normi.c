int	main(int argc, char **argv)
{
	pid_t	pid;
	size_t	strlen;
	const char *error = NULL;

	if (argc != 3)
		error = "Wrong number of arguments. You dummy.\n";
	else if (argv[2][0] == '\0')
		error = "You are sending an empty string. You dummy.\n";
	else if ((pid = ft_atoi(argv[1])) < 2)
		error = "PID has to be higher than 1. You dummy.\n";
	else if ((strlen = ft_strlen(argv[2])) > 4294967295)
		error = "Message is too long. Message was not sent. You dummy.\n";

	if (error)
		return (write(1, error, ft_strlen(error)), 1);

	send_strlen(pid, strlen);
	usleep(1);
	send_str(pid, argv[2], strlen);
	return (0);
}

{
	pid = ft_atoi(argv[1]);
	if (pid < 2)
		error = "PID has to be higher than 1. You dummy.\n";
	else
	{
		strlen = ft_strlen(argv[2]);
		if (strlen > 4294967295)
			error = "Message is too long. Message was not sent. You dummy.\n";
	}
}
