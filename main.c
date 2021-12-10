#include "ft_printf.h"

int	main()
{
	int	n = 20;
	int	*p = &n;
	char	*s = "%%\nMy name is: %s(%c)\nI'm %d or %i\nor in hex %x/%X\nthe pointer to it is %p\nthe unsigned %u\n";
	int	fttotal = ft_printf(s, "Cipher", 'M', n, n, n + 43, n + 43, p, 4294967295);
	ft_printf("\n");
	int	systotal = printf(s, "Cipher", 'M', n, n, n + 43, n + 43, p, 4294967295);
	ft_printf("\n");
	printf("Total sys printf: %d, total ft_printf: %d\n", systotal, fttotal);
	
	char *s = "%%x with -1[%x]\n";
	int n1 = ft_printf(s, -1);
	int n2 = printf(s, -1);
	printf("ft_printf: [%d] | printf: [%d]\n", n1, n2);

	return 0;
}
