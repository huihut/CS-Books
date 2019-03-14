/* dualview.c -- bit fields and bitwise operators */
#include <stdio.h>
/* BIT-FIELD CONSTANTS */
/* opaque and show */
#define YES     1
#define NO      0
/* line styles     */
#define SOLID   0
#define DOTTED  1
#define DASHED  2
/* primary colors  */
#define BLUE    4
#define GREEN   2
#define RED     1
/* mixed colors    */
#define BLACK   0
#define YELLOW  (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN    (GREEN | BLUE)
#define WHITE   (RED | GREEN | BLUE)

/* BITWISE CONSTANTS   */
#define OPAQUE          0x1
#define FILL_BLUE       0x8
#define FILL_GREEN      0x4
#define FILL_RED        0x2
#define FILL_MASK       0xE
#define BORDER          0x100
#define BORDER_BLUE     0x800
#define BORDER_GREEN    0x400
#define BORDER_RED      0x200
#define BORDER_MASK     0xE00
#define B_SOLID         0
#define B_DOTTED        0x1000
#define B_DASHED        0x2000
#define STYLE_MASK      0x3000

const char * colors[8] = {"black", "red", "green", "yellow",
            "blue", "magenta", "cyan", "white"};
struct box_props {

    unsigned int opaque         : 1;
    unsigned int fill_color     : 3;
    unsigned int                : 4;
    unsigned int show_border    : 1;
    unsigned int border_color   : 3;
    unsigned int border_style   : 2;
    unsigned int                : 2;
 };

union Views     /* look at data as struct or as unsigned short */
{
    struct box_props st_view;
    unsigned int     ui_view;
};

void show_settings(const struct box_props * pb);
void show_settings1(unsigned short);
char * itobs(unsigned int n, char * ps); 

int main(void)
{
    /* create Views object, initialize struct box view */
    union Views box = {{YES, YELLOW , YES, GREEN, DASHED}};
    char bin_str[8 * sizeof(unsigned int) + 1];

    printf("Original box settings:\n");
    show_settings(&box.st_view);
    printf("\nBox settings using unsigned int view:\n");
    show_settings1(box.ui_view);

    printf("bits are %s\n",
        itobs(box.ui_view,bin_str));
    box.ui_view &= ~FILL_MASK;          /* clear fill bits */
    box.ui_view |= (FILL_BLUE | FILL_GREEN); /* reset fill */
    box.ui_view ^= OPAQUE;               /* toggle opacity */
    box.ui_view |= BORDER_RED;           /* wrong approach */
    box.ui_view &= ~STYLE_MASK;        /* clear style bits */
    box.ui_view |= B_DOTTED;         /* set style to dotted*/
    printf("\nModified box settings:\n");
    show_settings(&box.st_view);
    printf("\nBox settings using unsigned int view:\n");
    show_settings1(box.ui_view);
    printf("bits are %s\n",
    itobs(box.ui_view,bin_str));
   
    return 0;
}

void show_settings(const struct box_props * pb)
{
    printf("Box is %s.\n",
            pb->opaque == YES? "opaque": "transparent");
    printf("The fill color is %s.\n", colors[pb->fill_color]);
    printf("Border %s.\n",
            pb->show_border == YES? "shown" : "not shown");
    printf("The border color is %s.\n", colors[pb->border_color]);
    printf ("The border style is ");
    switch(pb->border_style)
    {
        case SOLID  : printf("solid.\n"); break;
        case DOTTED : printf("dotted.\n"); break;
        case DASHED : printf("dashed.\n"); break;
        default     : printf("unknown type.\n");
    }
}

void show_settings1(unsigned short us)
{
    printf("box is %s.\n",
            us & OPAQUE == OPAQUE? "opaque": "transparent");
    printf("The fill color is %s.\n",
            colors[(us >> 1) & 07]);
    printf("Border %s.\n",
            us & BORDER == BORDER? "shown" : "not shown");
    printf ("The border style is ");
    switch(us & STYLE_MASK)
    {
        case B_SOLID  : printf("solid.\n"); break;
        case B_DOTTED : printf("dotted.\n"); break;
        case B_DASHED : printf("dashed.\n"); break;
        default       : printf("unknown type.\n");
    }
    printf("The border color is %s.\n",
            colors[(us >> 9) & 07]);

}

/* convert int to binary string */
char * itobs(unsigned int n, char * ps)
{
    int i;
    static int size = 8 * sizeof(unsigned int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';
   
    return ps;
}
