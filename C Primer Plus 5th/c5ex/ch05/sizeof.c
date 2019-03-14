// sizeof.c -- uses sizeof operator
// uses C99 %z modifier -- try %u or %lu if you lack %zd 
#include <stdio.h>
int main(void)
{
    int n = 0;
    size_t intsize;
  
    intsize = sizeof (int);
    printf("n = %d, n has %zd bytes; all ints have %zd bytes.\n",
         n, sizeof n, intsize );
         
    return 0;
}
