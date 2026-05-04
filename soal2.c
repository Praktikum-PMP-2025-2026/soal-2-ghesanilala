#include<stdio.h>
#include <stdlib.h>

// Structure for a node in a linked list
struct node {
  int data;
  struct node *next;
};

struct node *sorted(int n, int k, int i, int j, struct node *temp1, struct node *temp2, struct node *startList ){
    // Sorting the elements in ascending order using bubble sort
    for (i = n - 2; i >= 0; i--) {
        temp1 = startList;
        temp2 = temp1->next;
        for (j = 0; j <= i; j++) {
            if (temp1->data > temp2->data) {
                // Swapping data if the current node has a greater value than the next node
                k = temp1->data;
                temp1->data = temp2->data;
                temp2->data = k;
            }
            temp1 = temp2;
            temp2 = temp2->next;
        }
        return startList;
    }
}

struct node *sortedMerge(struct node *startList1, struct node *startList2) {
    // base cases
    if (startList1 == NULL)
        return startList1;
    if (startList2 == NULL)
        return startList2;

    // recursive merging based on smaller value
    if (startList1->data <= startList2->data) {
        startList1->next = sortedMerge(startList1->next, startList2);
        return startList1;
    }
    else {
        startList2->next = sortedMerge(startList1, startList2->next);
        return startList2;
    }
}

void printList(struct node *curr) {
    while (curr != NULL) {
        printf("%d\n", curr->data);
        }
        curr = curr->next;
    }


int main(){
    struct node *temp1, *temp2, *t, *newNode, *startList;
    int n, k, i, j;
    startList = NULL; 
    scanf("%d", &n);
    // Asking user to input the elements in the linked list
    for (i = 1; i <= n; i++) {
        if (startList == NULL) {
            // Creating a new node if the list is empty
            newNode = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &newNode->data);
            newNode->next = NULL;
            startList = newNode;
            temp1 = startList;
        } else {
            // Creating a new node if the list is not empty
            newNode = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &newNode->data);
            newNode->next = NULL;
            temp1->next = newNode;
            temp1 = newNode;
        }
    }
    struct node *head1 =  sorted(n,  k,  i,  j,  temp1, temp2, startList );

    struct node *temp12, *temp22, *t2, *newNode2, *startList2;
    int n2, k2, i2, j2;
    startList2 = NULL; 
    scanf("%d", &n2);

    for (i2 = 1; i2 <= n2; i2++) {
        if (startList2 == NULL) {
            // Creating a new node if the list is empty
            newNode2 = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &newNode2->data);
            newNode2->next = NULL;
            startList2 = newNode2;
            temp12 = startList2;
        } else {
            // Creating a new node if the list is not empty
            newNode2 = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &newNode2->data);
            newNode2->next = NULL;
            temp12->next = newNode2;
            temp12 = newNode2;
        }
    }

    struct node *head2 =  sorted(n2,  k2,  i2,  j2,  temp12, temp22, startList2 );
    struct node *res = sortedMerge(head1, head2);
    printList(res);
    return 0;
}

// https://www.geeksforgeeks.org/dsa/merge-two-sorted-linked-lists/
// https://www.w3resource.com/c-programming-exercises/linked_list/c-linked_list-exercise-30.php
