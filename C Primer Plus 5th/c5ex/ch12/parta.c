// parta.c --- various storage classes
#include <stdio.h>
void report_count();
void accumulate(int k);
int count = 0;       // file scope, external linkage

int main(void)
{
    int value;       // automatic variable
    register int i;  // register variable
    
    printf("Enter a positive integer (0 to quit): ");
    while (scanf("%d", &value) == 1 && value > 0)
    {
        ++count;     // use file scope variable
        for (i = value; i >= 0; i--)
            accumulate(i);
        printf("Enter a positive integer (0 to quit): ");
    }
    report_count();
    
    return 0;
}

void report_count()
{
    printf("Loop executed %d times\n", count);
}
