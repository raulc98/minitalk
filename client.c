#include "minitalk.h"

int	ft_atoi(char *str)
{
	long	nb;
	int		len;
	int		i;

	len = 0;
	while (str && str[len])
		len++;
	i = 0;
	nb = 0;
	while (i < len)
		nb = (nb * 10) + (str[i++] - 48);
	return (nb);
}

void	ft_send_signal(int pid, unsigned char c)
{
	int	arr[8];
	int	n;
	int	i;

	n = c;
	i = 7;
	while (i >= 0)
	{
		if (n == 0 || (n & 1) == 0)
			arr[i] = 0;
		else if ((n & 1) == 1)
			arr[i] = 1;
		if (n > 0)
			n >>= 1;
		i--;
	}
	while (++i < 8)
	{
		if (arr[i] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	unsigned char *str;
	
	if (argc != 3)
	{
		write(1, "Args error", 10);
		return (1);
	}

	pid = ft_atoi(argv[1]);
	str = (unsigned char *)argv[2];

	while (*str)
		ft_send_signal(pid, *str++);
	ft_send_signal(pid, '\n');

	return (0);
}
