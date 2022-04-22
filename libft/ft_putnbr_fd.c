
#include "libft.h"

int	ft_kolichestvo(int n)
{
	long int		j;

	j = 1;
	while (n != 0)
	{
		n = n / 10;
		j = j * 10;
	}
	j = j / 10;
	return (j);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long int		j;
	char				a;

	j = ft_kolichestvo(n);
	if (n < 0)
		write(fd, "-", 1);
	if (n == 0)
		write(fd, "0", 1);
	while (j != 0)
	{
		if (n >= 0)
		{
			a = n / j + '0';
			write(fd, &a, 1);
			n = n - (n / j) * j;
		}
		else
		{
			a = -(n / j) + '0';
			write(fd, &a, 1);
			n = n - (n / j) * j;
		}
		j = j / 10;
	}
}
