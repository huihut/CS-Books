/* copy2.c -- strcpy() demo */
#include <stdio.h>
#include <string.h>    /* declares strcpy() */
#define WORDS  "beast"
#define SIZE 40

int main(void)
{
    const char * orig = WORDS;
    char copy[SIZE] = "Be the best that you can be.";
    char * ps;

    puts(orig);
    puts(copy);
    ps = strcpy(copy + 7, orig);
    puts(copy);
    puts(ps);
   
    return 0;
}

