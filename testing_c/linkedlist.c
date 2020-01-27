#include <stdio.h>
#include <stdlib.h>

/*Declare structures */
typedef struct node {
    int val; 
    struct node *next;
} Node;

/*Declare functions*/
void print_list(Node *head);

int main() {

    //local var of head and alloc memory
    Node *head = NULL;
    head = (Node*)malloc(sizeof(Node));

    if(head == NULL) {
        printf("Head is null.");
    }

    head->val = 1;
   // head->next = NULL;

    //to add a var at the end of the list, need to advance the next pointer.
    head->next = (Node*)malloc(sizeof(Node));
    head->next->val = 2;
    head->next->next = NULL;

    print_list(head);
    
}


//iterate over the linked list
void print_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}


