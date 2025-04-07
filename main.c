#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to delete duplicates from the sorted linked list
struct ListNode* deleteDuplicates(struct ListNode* head) {
    // Create a fake node that acts like a fake head of the list pointing to the original head
    struct ListNode* fake = (struct ListNode*)malloc(sizeof(struct ListNode));
    fake->next = head; // Fake node points to the original head
    struct ListNode* pre = fake; // Pointer to the last node which has no duplicate
    struct ListNode* curr = head; // Pointer to traverse the linked list

    // Traverse the linked list
    while (curr != NULL) {
        // Skip all nodes with the same value
        while (curr->next != NULL && pre->next->val == curr->next->val) {
            curr = curr->next;
        }

        // If curr has a non-duplicate value, move the pre pointer to the next node
        if (pre->next == curr) {
            pre = pre->next;
        } else {
            // If curr is updated to the last duplicate value, discard it and connect pre and curr->next
            pre->next = curr->next;
        }

        // Move curr forward
        curr = curr->next;
    }

    // Return the modified linked list
    return fake->next;
}

// Helper function to create a linked list from an array
struct ListNode* createLinkedList(int* values, int size) {
    if (size == 0) return NULL;

    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = values[0];
    head->next = NULL;

    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = values[i];
        current->next = NULL;
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(struct ListNode* head) {
    printf("[");
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) {
            printf(",");
        }
        head = head->next;
    }
    printf("]\n");
}

// Main function to test the deleteDuplicates function
int main() {
    // Example 1
    int values1[] = {1, 2, 3, 3, 4, 4, 5};
    struct ListNode* head1 = createLinkedList(values1, sizeof(values1) / sizeof(values1[0]));
    printf("Input: head = [1,2,3,3,4,4,5]\n");
    struct ListNode* result1 = deleteDuplicates(head1);
    printf("Output: ");
    printLinkedList(result1);

    // Example 2
    int values2[] = {1, 1, 1, 2, 3};
    struct ListNode* head2 = createLinkedList(values2, sizeof(values2) / sizeof(values2[0]));
    printf("Input: head = [1,1,1,2,3]\n");
    struct ListNode* result2 = deleteDuplicates(head2);
    printf("Output: ");
    printLinkedList(result2);

    return 0;
}
