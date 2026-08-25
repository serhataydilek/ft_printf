#include <stdio.h>
#include "ft_printf.h"
int	main(void)
{
	printf("[%p]\n", (void *)0);
	ft_printf("[%p]\n", (void *)0);
	return (0);
}