#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Insert at the end of circular linked list
void insert(struct Node** last, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeofstruct Node));
    newNode->data = value;

    // If list is empty
    if (*last == NULL) {
        newNode->next = newNode;
        *last = newNode;
        return;
    }

    newNode->next = (*last)->next;
    (*last)->next = newNode;
    *last = newNode;
}

// Traverse circular linked list
void traverse(struct Node* last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = last->next; // first node
    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to head)\n");
}

// Delete a node by value
void deleteNode(struct Node** last, int value) {
    if (*last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *curr = (*last)->next;
    struct Node *prev = *last;

    do {
        if (curr->data == value) {

            // Only one node
            if (curr == *last && curr->next == curr) {
                free(curr);
                *last = NULL;
                return;
            }

            // Deleting last node
            if (curr == *last)
                *last = prev;

            prev->next = curr->next;
            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next;

    } while (curr != (*last)->next);

    printf("Value not found\n");
}

// Main function
int main() {
    struct Node* last = NULL;

    insert(&last, 10);
    insert(&last, 20);
    insert(&last, 30);

    traverse(last);

    deleteNode(&last, 20);
    traverse(last);

    deleteNode(&last, 10);
    traverse(last);

    return 0;
}
