#include <stddef.h>
#include <stdio.h>
#include "double_list.h"

static void populate_list ( double_list_t * list_head )
{
    double_list_add_elem_at_back ( list_head , 5.2) ;
    double_list_add_elem_at_back ( list_head , 42.5) ;
    double_list_add_elem_at_back ( list_head , 3.3) ;
}

static void test_size ( double_list_t list_head )
{
    printf (" There are %u elements in the list \n", double_list_get_size ( list_head ) ) ;
    double_list_dump ( list_head ) ;
}

static void test_del ( double_list_t * list_head )
{
    double_list_del_elem_at_back ( list_head ) ;
    printf (" There are %u elements in the list \n", double_list_get_size (* list_head ) ) ;
    double_list_dump (* list_head ) ;
}

int main ( void )
{
    double_list_t list_head = NULL;
    // ( list_head = *premiere_node)

    double_list_add_elem_at_back( &list_head, 5.2);
    double_list_add_elem_at_back( &list_head, 2.2);
    double_list_add_elem_at_back( &list_head, 3.2);
    double_list_add_elem_at_back( &list_head, 4.2);

    printf("%f\n\n", double_list_get_elem_at_position(list_head, 4));
    double_list_dump(list_head);
    printf("%d\n", double_list_get_size(list_head));
    doublelist_node_t *node = double_list_get_first_node_with_value(list_head, 2.2);
    printf("%f\n", (node)->value);
    return 0;
}