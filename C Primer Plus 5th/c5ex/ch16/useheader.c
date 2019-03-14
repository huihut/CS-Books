// useheader.c -- use the names_st structure
#include <stdio.h>
#include "names_st.h"
// remember to link with names_st.c

int main(void)
{
    names candidate;
    
    get_names(&candidate);
    printf("Let's welcome ");
    show_names(&candidate);
    printf(" to this program!\n");
    return 0;
}
