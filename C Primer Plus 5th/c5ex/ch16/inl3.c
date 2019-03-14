
#include <stdio.h>
extern double square(double);

double square(double x) { puts("exsq"); int y; y = x*x; return y; }

double sf(double a);

double sf(double a)
{
	
	puts("sf");
	return square(a);
}