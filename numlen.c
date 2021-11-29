#include "ft_printf.h"

int	numlen(unsigned int nbr)
{
	int	total;

	total = 0;
	while (nbr > 0)
	{
		total += 1;
		nbr /= 10;
	}
	return (total);
}
