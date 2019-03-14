/* reverse.c -- displays a file in reverse order */
#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032'   /* eof marker in DOS text files */
#define SLEN 50
int main(void)
{
    char file[SLEN];
    char ch;
    FILE *fp;
    long count, last;

    puts("Enter the name of the file to be processed:");
    gets(file);
    if ((fp = fopen(file,"rb")) == NULL)
    {                      /* read-only and binary modes */
        printf("reverse can't open %s\n", file);
        exit(1);
    }
    
    fseek(fp, 0L, SEEK_END);        /* go to end of file */
    last = ftell(fp);
/* if SEEK_END not supported, use this instead           */
/*  last = 0;
    while (getc(fp) != EOF)
        last++;
*/
    for (count = last- 1; count >= 0; count--)
    {
        fseek(fp, count, SEEK_SET); /* go backward       */
        ch = getc(fp);
    /* for DOS, works with UNIX */
        if (ch != CNTL_Z && ch != '\r')
            putchar(ch);
    /* for Macintosh            */
    /*  if (ch == '\r')
            putchar('\n');
         else
             putchar(ch)
    */
   }
   putchar('\n');
   fclose(fp);
   
   return 0;
}
