
#include <stdio.h>
extern double square(double);
inline double square(double);
double square(double x) { puts("sq1"); return x * x; }

double sff(double a);

double sff(double a)
{
	
	puts("sff");
	return square(a);
}