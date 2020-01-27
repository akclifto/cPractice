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
int remove_by_value(Node **head, int val);

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
    push_end(head, 15);
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

    printf("Removing node 2 from index:\n");
    remVal = remove_by_index(&head, 1);
    printf("Value removed from node: %d\n\n", remVal); //should be 1
    print_list(head);

    printf("Adding two more nodes to front of list!\n");
    push_front(&head, 16);
    push_front(&head, 21);
    print_list(head);
    
    printf("Removing node 1 from index:\n");
    remVal = remove_by_index(&head, 0);
    printf("Value removed from node: %d\n\n", remVal); //should be 21
    print_list(head);
    
    printf("Removing node with value 2 from index:\n");
    remVal = remove_by_value(&head, 2);
    printf("Value removed from node: %d\n\n", remVal); //should be 2
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
    
    int retVal = -1;
    Node *next;
    if(head == NULL) {
        return retVal;
    }
    //since we're modifying the head node, we need to point to it here to get next
    next = (*head)->next;
    retVal = (*head)->val;
    *head = next;

    //return the value from the node, we just removed
    return retVal;
}

/*Remove the last node in the list*/
int remove_end(Node *head) {

    int retVal = 0;
    //base case: if there's only one node
    if(head->next == NULL) {
        retVal = head->val;
        free(head);
        return retVal;
    }

    //find the second to last node, set current node pointer to it.
    Node *current = head;
    while(current->next->next != NULL) {
        current = current->next;
    }

    //capture val from last node, remove last node, free the memory, set current-> to null
    retVal = current->next->val;
    free(current->next);
    current->next = NULL;

    return  retVal;
}

/*Remove a specific item from the linked list, by node index */
int remove_by_index(Node **head, int index) {
    
    int i = 0;
    int retVal = -1;
    Node *current = *head;
    Node *temp = NULL;

    //if its the first index in the list.
    if(index == 0) {
        return remove_head(head);
    }

    //loop through list to get to the node just before the one we want to remove.
    for(i = 0; i < index - 1; i++) { 
        if(current->next == NULL) {
           return retVal; 
        }
        current = current->next;
    }

    //set temp to node for removal, store its val, set curr->next to node after 
    //node we are removing, free temp from memory
    temp = current->next;
    retVal = temp->val;
    current->next = temp->next;
    free(temp);

    //return val of removed node.
    return retVal;
}

/* Remove node by value from list.*/
int remove_by_value(Node **head, int val) {

    Node *current = *head;
    Node *previous = NULL;

    if(current == NULL) { 
        return -1;
    }
    
    //if first node is the node to remove by value
    if(current->val == val) {
        return remove_head(head);
    }

    previous = current;
    current = (*head)->next;
    //if current value == value, set prev to jump the removed node, free current , return val.
    while(current != NULL) {

        if(current->val == val) {
            previous->next = current->next;
            free(current);
            return val;
        }
        //else keep moving through the list.
        previous = current;
        current = current->next;
    }

    //if not found
    return -1;
}

