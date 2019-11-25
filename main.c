#include "ft_printf.h"
// #include <stdio.h>

// #include <unistd.h>
// #include <stdlib.h>
#include <float.h>
#include <limits.h>	

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


	
	ft_printf("%bd\n", 255);
	
	// printf("%-dn", INT_MIN)
	return (0);
}
// Test 1278 (o_prec0val0_af) : FAILED.
//     First line of code: {return test("%#.0o", 0);}
//       expected output : "0"
//       your output     : ""
//       expected (nonprintable as hex) : "0"
//       actual   (nonprintable as hex) : ""

// Test 1279 (o_prec0val0_af_impl) : FAILED.
//     First line of code: {return test("%#.o", 0);}
//       expected output : "0"
//       your output     : ""
//       expected (nonprintable as hex) : "0"
//       actual   (nonprintable as hex) : ""

