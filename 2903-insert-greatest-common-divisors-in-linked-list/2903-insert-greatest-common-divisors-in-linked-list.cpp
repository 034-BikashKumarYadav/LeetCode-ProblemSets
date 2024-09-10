/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
    }
};*/

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head; // If the list is empty or has only one node, no need to insert GCD nodes.

        ListNode* current = head;
        while (current->next != nullptr) {
            int gcdValue = gcd(current->val, current->next->val);
            ListNode* newNode = new ListNode(gcdValue);
            newNode->next = current->next;
            current->next = newNode;
            current = current->next->next;
        }

        return head;
    }
};