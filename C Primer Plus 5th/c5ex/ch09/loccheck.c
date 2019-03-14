/* loccheck.c  -- checks to see where variables are stored  */
#include <stdio.h>
void mikado(int);                      /* declare function  */
int main(void)
{
    int pooh = 2, bah = 5;             /* local to main()   */

    printf("In main(), pooh = %d and &pooh = %p\n",
            pooh, &pooh);
    printf("In main(), bah = %d and &bah = %p\n",
            bah, &bah);
    mikado(pooh);
    
    return 0;
}

void mikado(int bah)                   /* define function   */
{
    int pooh = 10;                     /* local to mikado() */

    printf("In mikado(), pooh = %d and &pooh = %p\n",
            pooh, &pooh);
    printf("In mikado(), bah = %d and &bah = %p\n",
            bah, &bah);
}
