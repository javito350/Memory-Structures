#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "pico/stdlib.h"
#include "headers/assignment.h"

struct values {
    int value;
    struct values* next;
};

struct values* add_node(int value) {
    struct values* new_node = (struct values*)malloc(sizeof(struct values));
    if (new_node != NULL) {
        new_node->value = value;
        new_node->next = NULL;
    }
    return new_node;
}

int checkpoint(void) {
    return 0;
}

struct values* create_list() {
    extern int data[];
    struct values* head = NULL;
    struct values* current = NULL;
    
    // Calculate the number of elements in data array
    int data_count = 100; // There are 100 elements in the data array
    
    for (int i = 0; i < data_count; i++) {
        struct values* new_node = add_node(data[i]);
        if (head == NULL) {
            head = new_node;
            current = head;
        } else {
            current->next = new_node;
            current = new_node;
        }
    }
    
    return head;
}

struct values* remove_node(struct values* head, int threshold) {
    struct values* current = head;
    struct values* prev = NULL;
    
    // Remove nodes from the beginning if they meet the condition
    while (current != NULL && current->value >= threshold) {
        struct values* temp = current;
        head = current->next;
        current = current->next;
        free(temp);
    }
    
    // Remove nodes from the middle or end
    prev = head;
    if (current != NULL) {
        current = current->next;
    }
    
    while (current != NULL) {
        if (current->value >= threshold) {
            struct values* temp = current;
            prev->next = current->next;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    return head;
}

int list_length(struct values* head) {
    int count = 0;
    struct values* current = head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

int list_size(struct values* head) {
    int count = list_length(head);
    return count * sizeof(struct values);
}

int main(void) {
    stdio_init_all();
    
    // Create the linked list from the data array
    printf("Creating linked list...\n");
    struct values* head = create_list();
    
    // Display initial statistics
    printf("Initial list length: %d nodes\n", list_length(head));
    printf("Initial list size: %d bytes\n", list_size(head));
    
    // Remove nodes with values >= 500
    int threshold = 500;
    printf("\nRemoving nodes with value >= %d...\n", threshold);
    head = remove_node(head, threshold);
    
    // Display final statistics
    printf("Final list length: %d nodes\n", list_length(head));
    printf("Final list size: %d bytes\n", list_size(head));
    
    // Clean up memory
    struct values* current = head;
    while (current != NULL) {
        struct values* temp = current;
        current = current->next;
        free(temp);
    }
    
    return checkpoint();
}