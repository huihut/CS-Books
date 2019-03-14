
#include <stdio.h>
inline double square(double);
double square(double x) { puts("sq1"); return x * x; }

double sf(double a);
double sff(double a);

int main()
{
    double q = 20;
    double x;
    
    x = square(q);
    printf("inl1, square: %f\n", x);
    x = sf(q);
    printf("inl1, sf: %f\n", x);
    x = sff(q);
    printf("inl1, sff: %f\n", x);
 
    return 0;
}

