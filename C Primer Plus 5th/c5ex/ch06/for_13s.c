/* for_13s.c */
#include <stdio.h>
int main(void)
{
    int n;        /* count by 13s */

    for (n = 2;  n < 60; n = n + 13)
        printf("%d \n", n);
    return 0;
}
