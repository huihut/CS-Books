/* r_drive0.c -- test the rand0() function */
/* compile with rand0.c                    */
#include <stdio.h>
extern int rand0(void);

int main(void)
{
    int count;

    for (count = 0; count < 5; count++)
        printf("%hd\n", rand0());
    
    return 0;
}
