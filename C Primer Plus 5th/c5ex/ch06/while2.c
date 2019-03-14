/* while2.c -- watch your semicolons */
#include <stdio.h>
int main(void)
{
    int n = 0;

    while (n++ < 3);             /* line 7 */
        printf("n is %d\n", n);  /* line 8 */
    printf("That's all this program does.\n");
   
    return 0;
}
