#include "ft_printf.h"

int main()
{
	int n = 20;
	int *p = &n;
	int fttotal = ft_printf("My name is: %s(%c) I'm %d or %i or in hex %x/%X the pointer to it is %p the unsigned %u\n", "Cipher", 'M', n, n, n + 43, n + 43, p, 4294967295);
	int systotal = printf("My name is: %s(%c) I'm %d or %i or in hex %x/%X the pointer to it is %p the unsigned %lu\n", "Cipher", 'M', n, n, n + 43, n + 43, p, 4294967295);
	printf("Total sys printf: %d, total ft_printf: %d\n", systotal, fttotal);
	return 0;
}