// doubincl.c -- include header twice
#include <stdio.h>
#include "names_str.h"   // revised version of names_st.h
#include "names_str.h"   // accidental second inclusion

int main()
{
    names winner = {"Less", "Ismoor"};
    printf("The winner is %s %s.\n", winner.first,
            winner.last);
    return 0;
}
