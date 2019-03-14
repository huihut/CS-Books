// partb.c -- rest of the program
#include <stdio.h>

extern int count;       // reference declaration, external linkage

static int total = 0;   // static definition, internal linkage
void accumulate(int k); // prototype


void accumulate(int k)  // k has block scope, no linkage
{
    static int subtotal = 0;  // static, no linkage
    
    if (k <= 0)
    {
        printf("loop cycle: %d\n", count);
        printf("subtotal: %d; total: %d\n", subtotal, total);
        subtotal = 0;
    }
    else
    {
        subtotal += k;
        total += k;
    }
}
