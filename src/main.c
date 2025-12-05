#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "pico/stdlib.h"
#include "headers/assignment.h"

struct values {
    // TODO: Define struct fields
};

add_node() {
    // TODO: Allocate memory for and define values(s) of struct
}

int checkpoint(void) {
    return 0;
}

create_list() {
    // TODO: Create the list node by node using iteration
}

remove_node() {
    // TODO: Create logic to remove and reset prior struct nodes
    //       given an arbitrary value
}

list_length() {
    // TODO: Iterate over nodes of linked list to count the number
    //       of nodes contained
}

list_size() {
    // TODO: Calculate the overall size of the linked list
}

int main(void) {
    stdio_init_all();
    // TODO: Create list and call functions to achieve:
    //       - list creation
    //       - list removal
    //       - list element count
    //       - total list size
    return checkpoint();
}