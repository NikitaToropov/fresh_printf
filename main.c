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
	// printf("%08f\n", -3.4/0);
	printf("%+.Lf\n", 0.0L);
	ft_printf("%+.Lf", 0.0L);
	return (0);
}


    //           -01867
    //   -01867