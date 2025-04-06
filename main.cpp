#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* new_head = nullptr; // Pointer to the new head of the list
        ListNode* prev = nullptr;     // Pointer to the previous node in the new list
        ListNode* node = head;        // Pointer to traverse the original list

        while (node) {
            ListNode* next = node->next;
            bool remove = false;

            // Skip all nodes with the same value
            while (next && node->val == next->val) {
                next = next->next;
                remove = true;
            }

            // If the current node is not a duplicate, add it to the new list
            if (!remove) {
                if (!new_head) {
                    new_head = node;
                } else {
                    prev->next = node;
                }
                prev = node;
            }

            // Move to the next distinct node
            node = next;
        }

        // Terminate the new list
        if (prev) {
            prev->next = nullptr;
        }

        return new_head;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print a linked list in the required format
void printLinkedList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) {
            cout << ",";
        }
        head = head->next;
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;

    // Example 1
    vector<int> values1 = {1, 2, 3, 3, 4, 4, 5};
    ListNode* head1 = createLinkedList(values1);
    cout << "Input: head = [1,2,3,3,4,4,5]" << endl;
    ListNode* result1 = solution.deleteDuplicates(head1);
    cout << "Output: ";
    printLinkedList(result1);

    // Example 2
    vector<int> values2 = {1, 1, 1, 2, 3};
    ListNode* head2 = createLinkedList(values2);
    cout << "Input: head = [1,1,1,2,3]" << endl;
    ListNode* result2 = solution.deleteDuplicates(head2);
    cout << "Output: ";
    printLinkedList(result2);

    return 0;
}
