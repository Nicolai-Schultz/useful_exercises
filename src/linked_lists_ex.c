#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
    //  Siden instancet er en pointer gemmer den ikke nok plads i lageret til at kunne
    //  printe en int. Der skal explicit malloces senere, ellers skal instancet ændres
    //  til at være udelukkende en int.
    int* data;
    struct linked_list *next;
} linked_list_s;

int main(void) {
    //  Declaring struct node and mallocing
    linked_list_s *n1, *n2, *n;
    n1 = (linked_list_s *) malloc(sizeof(linked_list_s));
    n2 = (linked_list_s *) malloc(sizeof(linked_list_s));

    if(n1 == NULL) {
        printf("Memory not allocated");
    }

    //  Initializing node 1
    n1->data = (int*)malloc(sizeof(int)); // Allocate memory for data
    *(n1->data) = 10;
    n1->next = n2;
    // node 2

    n2->data = (int*)malloc(sizeof(int)); // Allocate memory for data
    *(n2->data) = 30;
    n2->next = NULL;

    //  duplicate variable as not to alter n1
    n = n1;
    while(n != NULL) {
        printf("%d \n", *n->data);
        n = n->next;
    }

    free(n1);
    free(n2);

}
