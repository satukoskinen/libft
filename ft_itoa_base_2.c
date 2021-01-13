#include <stdlib.h>
#include <stdio.h>

int		ft_abs(int value)
{
	return ((value >= 0 ? value : -value));
}

char	*ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_itoa_base(int value, int base)
{
	char	*result;
	char	*digits;
	char	temp[32 + 1];
	int		i;
	int		sign;

	digits = "0123456789ABCDEF";
	i = 32;
	sign = (value < 0) ? -1 : 1;
	temp[i--] = '\0';
	if (value != 0 && base >= 2 && base <= 16)
	{
		while (value != 0)
		{
			temp[i--] = digits[ft_abs(value % base)];
			value = value / base;
		}
		if (sign == -1 && base == 10)
			temp[i--] = '-';
	}
	else
		temp[i--] = '0';
	if (base < 2 || base > 16 || !(result = (char*)malloc(32 - i + 1)))
		return (NULL);
	return (ft_strcpy(result, &temp[i + 1]));
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%s\n", ft_itoa_base(atoi(argv[1]), atoi(argv[2])));
	}
	return (0);
}