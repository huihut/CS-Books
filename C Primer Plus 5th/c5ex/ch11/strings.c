// strings.c -- stringing the user along
#include <stdio.h>
#define MSG "You must have many talents. Tell me some."
                          // a symbolic string constant
#define LIM  5
#define LINELEN 81        // maximum string length + 1
int main(void)
{
    char name[LINELEN];
    char talents[LINELEN];
    int i;
                          // initializing a dimensioned
                          // char array       
    const char m1[40] = "Limit yourself to one line's worth.";
                          // letting the compiler compute the
                          // array size     
    const char m2[] = "If you can't think of anything, fake it.";
                          // initializing a pointer  
    const char *m3 = "\nEnough about me -- what's your name?";
                          // initializing an array of
                          // string pointers         
    const char *mytal[LIM] = {  // array of 5 pointers
          "Adding numbers swiftly",
          "Multiplying accurately", "Stashing data",
          "Following instructions to the letter",
          "Understanding the C language"
          };

    printf("Hi! I'm Clyde the Computer."
           " I have many talents.\n");
    printf("Let me tell you some of them.\n");
    puts("What were they? Ah, yes, here's a partial list.");
    for (i = 0; i < LIM; i++)
        puts(mytal[i]);   // print list of computer talents
    puts(m3);
    gets(name);
    printf("Well, %s, %s\n", name, MSG);
    printf("%s\n%s\n", m1, m2);
    gets(talents);
    puts("Let's see if I've got that list:");
    puts(talents);
    printf("Thanks for the information, %s.\n", name);
  
    return 0;
}
