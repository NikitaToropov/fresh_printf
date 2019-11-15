#include "ft_printf.h"
// #include <stdio.h>

// #include <unistd.h>
// #include <stdlib.h>
#include <float.h>

// test %-7C %007d%-10.2ls!!, 0xd777, 0x45, L"〻
int		main(void)
{	

	// ft_printf("%12.4lli%+ 0.Lf%-020.5str\n", i, -152.0L, 8562, "qwertyuiopoiuytrew");
	// printf("%12.4lli%+ 0.Lf%-020.5str\n", i, -152.0L, 8562, "qwertyuiopoiuytrew");

	// printf("%12.4lli%+ 0.Lf%-020.5str\n", i, -152.0L, "qwertyuiopoiuytrew");
	// ft_printf("%12.4lli%+ 0.Lf%-020.5str\n", i, -152.0L, "qwertyuiopoiuytrew");
	
	// printf("%+.0i\n", 0);
	
	// printf("t%#.4o\n", 012);
	// ft_printf("t%#.4o\n", 012);
	
	// printf("%o\n", 012);
	// printf("%#o\n", 012);
	// printf("%.4o\n\n", 012);

	printf("%0#14.3o\n", 12587499);
	ft_printf("%0#14.3o\n", 12587499);
	return (0);
}
// TEST : test%#.4o et %02o %0#14.0o!!, 012, 036, 12587499
// ft_printf  --> test00012 et 36      060010753!!
// ret = 32
// printf     --> test0012 et 36      060010753!!
// ret = 31
// [KO]