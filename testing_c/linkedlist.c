#include <stdio.h>
#include <stdlib.h>

/*Declare structures */
typedef struct node {
    int val; 
    struct node *next;
} Node;

/*Declare functions*/

void print_list(Node *head);
void push_end(Node *head, int val);
void push_front(Node **head, int val);
int remove_head(Node **head);
int remove_end(Node *head);
int remove_by_index(Node **head, int val);

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
    push_end(head, 10);
    print_list(head);

    /*since pushing to the front and modifying the head node,
    *   we use a point to the address of the head node (the & symbol).
    */
    push_front(&head, 7);
    push_front(&head, 13);
    print_list(head);

    printf("Removing the head of the list\n");
    int remVal = remove_head(&head); //should remove 13
    printf("Value removed from node: %d\n\n", remVal);
    print_list(head);

    printf("Removing end node of the list\n");
    remVal = remove_end(head);
    printf("Value removed from node: %d\n\n", remVal);
    print_list(head);
    
}


/*iterate over the linked list*/
void print_list(Node *head) {

    Node *current = head;
    int nodeCount = 0;

    printf("Beginning of print list:\n");
    while (current != NULL) {
        printf("node %d: %d\n", nodeCount + 1, current->val);
        nodeCount++;
        current = current->next;
    }
    printf("End of print list!\n\n");
}

//adding an item to the END of the list.
void push_end(Node *head, int val) {

    Node *current = head;
    //get to the end of the list with a pointer.
    while(current->next != NULL) {
        current = current->next;
    }

    //now at the end, add the val to the end of the list
    current->next = (Node*)malloc(sizeof(Node));
    current->next->val = val;
    //ensure the end of the list is set to null
    current->next->next = NULL;

}

//adding an item at the beginning of the list.
/*  double pointer: since using a function (gets one *), we need to modify the head variable 
 *  being passed in the parameter (gets another *). 
 *  Do do this, need a pointer to a pointer, ie,  Node **head
 */
void push_front(Node **head, int val) {

    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));

    //set the val in the new node, then have its next node point to the current head.
    newNode->val = val;
    newNode->next = *head; 
    *head = newNode; //need the * here to make sure we're modifying head node
}

/*remove the head of the linked list*/
int remove_head(Node **head) {
    
    int returnVal = -1;
    Node *next;
    if(head == NULL) {
        return returnVal;
    }
    //since we're modifying the head node, we need to point to it here to get next
    next = (*head)->next;
    returnVal = (*head)->val;
    *head = next;

    //return the value from the node, we just removed
    return returnVal;
}

/*Remove the last node in the list*/
int remove_end(Node *head) {

    int returnVal = 0;
    //base case: if there's only one node
    if(head->next == NULL) {
        returnVal = head->val;
        free(head);
        return returnVal;
    }

    //find the second to last node, set current node pointer to it.
    Node *current = head;
    while(current->next->next != NULL) {
        current = current->next;
    }

    //capture val from last node, remove last node, free the memory, set current-> to null
    returnVal = current->next->val;
    free(current->next);
    current->next = NULL;

    return  returnVal;
}

/*Remove a specific item from the linked list, by val */
int remove_by_index(Node **head, int val) {
    
}

