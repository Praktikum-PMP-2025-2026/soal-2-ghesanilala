#include<stdio.h>
#include <stdlib.h>

// Structure for a node in a linked list
struct node {
  int data;
  struct node *next;
};

// struct node *sorted(int n, int k, int i, int j, struct node *temp1, struct node *temp2, struct node *startList ){
//     // Sorting the elements in ascending order using bubble sort
//     for (i = n - 2; i >= 0; i--) {
//         temp1 = startList;
//         temp2 = temp1->next;
//         for (j = 0; j <= i; j++) {
//             if (temp1->data > temp2->data) {
//                 // Swapping data if the current node has a greater value than the next node
//                 k = temp1->data;
//                 temp1->data = temp2->data;
//                 temp2->data = k;
//             }
//             temp1 = temp2;
//             temp2 = temp2->next;
//             startList = temp1;
//             return startList;
//         }
//     }


struct node *sortedMerge(struct node *startList1, struct node *startList2) {
    // base cases
    if (startList1 == NULL)
        return startList1;
    if (startList2 == NULL)
        return startList2;

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
        printf("MERGED");
        printf("%d\n", curr->data);
        }
        curr = curr->next;
    }


int main(){
    struct node *temp1, *temp2, *t, *newNode, *startList1;
    int n, k, i, j;
    startList1 = NULL; 
    scanf("%d", &n);
    // Asking user to input the elements in the linked list
    for (i = 1; i <= n; i++) {
        if (startList1 == NULL) {
            // Creating a new node if the list is empty
            newNode = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &newNode->data);
            newNode->next = NULL;
            startList1 = newNode;
            temp1 = startList1;
        } else {
            // Creating a new node if the list is not empty
            newNode = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &newNode->data);
            newNode->next = NULL;
            temp1->next = newNode;
            temp1 = newNode;
        }
    }
        for (i = n - 2; i >= 0; i--) {
        temp1 = startList1;
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
    }

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
    for (i2 = n2 - 2; i2 >= 0; i2--) {
        temp12 = startList2;
        temp22 = temp12->next;
        for (j2 = 0; j2 <= i2; j2++) {
            if (temp12->data > temp22->data) {
                // Swapping data if the current node has a greater value than the next node
                k2 = temp1->data;
                temp12->data = temp22->data;
                temp22->data = k2;
            }
            temp12 = temp22;
            temp22 = temp22->next;
        }
    }
    struct node *res = sortedMerge(startList1, startList2);
    printList(res);
    return 0;
}

// https://www.geeksforgeeks.org/dsa/merge-two-sorted-linked-lists/
// https://www.w3resource.com/c-programming-exercises/linked_list/c-linked_list-exercise-30.php
