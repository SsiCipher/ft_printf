#include "ft_printf.h"

int	main()
{
	int	n = 20;
	int	*p = &n;
	int	fttotal = ft_printf("%%\nMy name is: %s(%c)\nI'm %d or %i\nor in hex %x/%X\nthe pointer to it is %p\nthe unsigned %u\n", "Cipher", 'M', n, n, n + 43, n + 43, p, 4294967295);
	ft_printf("\n");
	int	systotal = printf("%%\nMy name is: %s(%c)\nI'm %d or %i\nor in hex %x/%X\nthe pointer to it is %p\nthe unsigned %lu\n", "Cipher", 'M', n, n, n + 43, n + 43, p, 4294967295);
	ft_printf("\n");
	printf("Total sys printf: %d, total ft_printf: %d\n", systotal, fttotal);
	return 0;
}
