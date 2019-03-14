/* typesize.c -- prints out type sizes */
#include <stdio.h>
int main(void)
{
/* c99 provides a %zd specifier for sizes */
    printf("Type int has a size of %u bytes.\n", sizeof(int));
    printf("Type char has a size of %u bytes.\n", sizeof(char));
    printf("Type long has a size of %u bytes.\n", sizeof(long));
    printf("Type double has a size of %u bytes.\n",
            sizeof(double));
    return 0;
}
