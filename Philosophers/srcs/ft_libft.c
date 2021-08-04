#include "../include/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && (len > i))
	{
		j = 0;
		if (needle[j] == 0)
			return ((char *)haystack);
		while ((needle[j] != 0)
			&& ((haystack[i + j] == needle[j]) && len > i + j))
		{
			j++;
		}
		if (needle[j] == 0)
			return (((char *)haystack) + i);
		i++;
	}
	return (NULL);
}

void	ft_check(const char *str, int *manus, int *a)
{
	while ((str[*a] >= 9 && str[*a] <= 13) || str[*a] == 32)
		(*a)++;
	if (str[*a] == '+' || str[*a] == '-')
	{
		if (str[*a] == '-')
			(*manus) = -1;
		(*a)++;
	}
}

void	ft_atoiset(int *flag, int *manus, long long int *result, int *a)
{
	(*flag) = 1;
	(*result) = 0;
	(*a) = 0;
	(*manus) = 1;
}

int	ft_atoi(const char *str)
{
	int				a;
	long long int	result;
	int				manus;
	int				flag;

	ft_atoiset(&flag, &manus, &result, &a);
	ft_check(str, &manus, &a);
	while (str[a] >= '0' && str[a] <= '9')
	{
		if (result >= 214748365 || (result >= 214748364
				&& (str[a] == '8' || str[a] == '9')))
			return (-1);
		if (result <= -214748365 || (result <= -214748364 && (str[a] == '9')))
			return (0);
		if (result == 0)
			result = str[a] - '0';
		else if (a > 0 && result > 0)
			result = result * 10 + (str[a] - '0');
		else if (a > 0 && result < 0)
			result = result * 10 - (str[a] - '0');
		if (result != 0 && (manus == -1 && (flag++) == 1))
			result = result * manus;
		a++;
	}
	return (result);
}
