#include "fractol.h"

void	write_str(char *str)
{
	int	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	print_error(char *str)
{
	write_str(str);
	write(1, "\n", 1);
	exit(1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

double	ft_atof(const char *str)
{
	double	result;
	double	frac;
	int		sign;
	int		i;

	result = 0.0;
	frac = 0.1;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result += (str[i++] - '0') * frac;
			frac /= 10;
		}
	}
	return (result * sign);
}

double ft_fabs(double x)
{
    if (x < 0)
        return -x;
    else
        return x;
}
