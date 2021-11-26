#include "ft_printf.h"

// Print Character
int	put_char(char c)
{
	return (write(1, &c, 1));
}

// Print String
int	put_str(char *str)
{
	int	total;

	total = 0;
	while (*str)
		total += write(1, str++, 1);
	return (total);
}

int numlen(unsigned int nbr)
{
	int total = 0;

	while (nbr > 0)
	{
		total += 1;
		nbr /= 10;
	}

	return (total);
}

// Print Number(int)
int	put_nbr(int nbr)
{
	int			num;
	static int	total;

	if (nbr < 0)
	{
		if (nbr == -2147483648)
			return (write(1, "-2147483648", 11));
		else
		{
			total += 1;
			write(1, "-", 1);
			put_nbr(-nbr);
		}
	}
	else
	{
	    total += 1;
		if (nbr >= 10)
		    put_nbr(nbr / 10);
		num = nbr % 10 + '0';
		write(1, &num, 1);
	}
	return (total);
}

// Print Unsigned number(uint)
int	put_unbr(unsigned int nbr)
{
	unsigned int	num;
	static int		utotal;

	utotal += 1;
	if (nbr >= 10)
		put_unbr(nbr / 10);
	num = nbr % 10 + '0';
	write(1, &num, 1);
	return (utotal);
}

// Print Int In Hex
int	put_hex(int n, char c_case)
{
	int		i;
	int		total;
	char	*base;
	char	result[16];

	if (c_case == 'x')
		base = "0123456789abcdef";
	else if (c_case == 'X')
		base = "0123456789ABCDEF";

	i = 0;
	while (n > 0)
	{
	    result[i++] = base[n % 16];
	    n /= 16;
	}

	total = 0;
	while (--i >= 0)
	    total += write(1, &result[i], 1);

	return (total);
}

// Print Pointer Address
int	put_ptr(unsigned long n)
{
	int		i;
	int		total;
	char	*base;
	char	result[16];

	i = 0;
	base = "0123456789abcdef";
	while (n > 0)
	{
	    result[i++] = base[n % 16];
	    n /= 16;
	}

	total = put_str("0x");
	while (--i >= 0)
	    total += write(1, &result[i], 1);

	return (total);
}

// int main(int argc, char const *argv[])
// {
// 	// int	total_char = put_char('c');
// 	// int	total_str = put_str("hello");
// 	int	total_nbr = put_nbr(123456);
// 	int	total_unbr = put_unbr(354545878);
// 	int	total_nbr1 = put_nbr(123456);
// 	// int	total_unbr1 = put_unbr(4);
// 	// int	total_hex = put_hex(1234, 'X');
// 	// int	total_ptr = put_ptr(1234578945612);

// 	// printf("\n%d\n%d\n%d\n%d\n%d\n%d\n", total_char, total_str, total_nbr, total_unbr, total_hex, total_ptr);
// 	printf("\n%d\n%d\n%d\n", total_nbr, total_unbr, total_nbr1);

// 	return 0;
// }
