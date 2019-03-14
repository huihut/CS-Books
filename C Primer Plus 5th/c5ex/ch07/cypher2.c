// cypher2.c -- alters input, preserving non-letters
#include <stdio.h>
#include <ctype.h>            // for isalpha()
int main(void)
{
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))      // if a letter,
            putchar(ch + 1);  // change it
        else                  // otherwise,
            putchar(ch);      // print as is
    }
    putchar(ch);              // print the newline
   
    return 0;
}
