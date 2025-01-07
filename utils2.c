#include "so_long.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	r;
	size_t	sign;
	char	*s;

	s = (char *)str;
	i = 0;
	r = 0;
	sign = 1;
	while (s[i] == ' ' || (s[i] >= 8 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		r *= 10;
		r += (s[i] - 48);
		i++;
	}
	return ((int)(r * sign));
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = (long int)n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}