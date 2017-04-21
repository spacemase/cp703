/******************************************************************************
 * FILE:  less16.c
 * Description:  enumerated types
 *****************************************************************************/

typedef enum color_tag
{
    RED = 12,    /* 12 */
    GREEN,       /* 13 */
    BLUE,        /* 14 */
    PURPLE,      /* 15 */
    WHITE,       /* 16 */
    BLACK,       /* 17 */
    RED2 = RED,  /* 12 OK - RED2 is a synonym for RED     */
    RED3         /* 13 OK - RED3 is a synonym for GREEN?? */
} COLOR_t;

static COLOR_t get_color( COLOR_t my_color );

int main( void )
{
    COLOR_t my_color = WHITE;
    int other_color = WHITE;

   /*
    * can use enum identifiers like constant integers
    */
    other_color = RED;

   /* 
    * or, you can have variables of an enumerated type
    */
    my_color = get_color( my_color );
    my_color = get_color( RED );
    my_color = get_color( 12 );

   /*
    * a C compiler will generally allow these without warning
    */
    my_color = get_color( -12);
}
static COLOR_t get_color( COLOR_t my_color )
{
    if ( my_color == RED )
        return PURPLE;
    else
        return GREEN;
}

