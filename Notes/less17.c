/******************************************************************************
 * FILE: less17.c
 * Description: program illustrating linked list concepts
 ******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct sup_hero_s
{
    struct sup_hero_s * next;
    const char * name;
} sup_hero_t, *sup_hero_p_t;



int main( void )
{
    sup_hero_p_t head = NULL;
    sup_hero_p_t tail = NULL;
    sup_hero_p_t list_item = NULL;
    sup_hero_p_t found_item = NULL;

    const char **sup_hero_ptr = NULL;
    const char * sup_hero_data[] =  { "Wonder Woman",
                                      "Green Lantern",
                                      "The Hulk",
                                      "Cat Woman",
                                       NULL };

    printf( "Create the list \n" );
    /* cycle the array of pointers to strings */
    sup_hero_ptr = sup_hero_data;
    while ( *sup_hero_ptr )
    {
        sup_hero_t * mem_ptr = malloc( sizeof( sup_hero_t ) );
        mem_ptr->name = *sup_hero_ptr;
        mem_ptr->next = NULL;
        /* if the list is "empty", add to head */
        if ( head == NULL )
        {
            head = tail = mem_ptr;
        }
        /* otherwise add to tail */
        else
        {
            tail->next = mem_ptr;
            tail = tail->next;
        }
        sup_hero_ptr++;
    }

    puts( "Cycle the list" );
    list_item = head;
    while ( list_item )
    {
        printf("\t%s\n", list_item->name );
        list_item = list_item->next;
    }

    printf( "Remove head from list \"%s\"\n", head->name );
    list_item = head;
    head = head->next;
    printf("REMOVED %s\n", list_item->name );
    free( list_item );
    list_item = NULL;

    puts( "Cycle the list" );
    list_item = head;
    while ( list_item )
    {
        printf("\t%s\n", list_item->name );
        list_item = list_item->next;
    }

    list_item = head->next;
    printf( "Remove middle item from list \"%s\"\n", list_item->name );
    head->next = head->next->next;
    free( list_item );
    puts( "Cycle the list" );
    list_item = head;
    while ( list_item )
    {
        printf("\t%s\n", list_item->name );
        list_item = list_item->next;
    }

    printf( "Destroy the list\n" );
    while ( head )
    {
        sup_hero_p_t temp_item = head;
        head = head->next;
        free( temp_item );
    }
    tail = NULL;
}



