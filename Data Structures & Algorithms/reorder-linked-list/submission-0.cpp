/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        
        /* Fast and slow pointer to find the middle of the linked list */
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) { // ensure that both the current node and a next node exists so no out of bounds
            slow = slow->next;
            fast = fast->next->next;
        }

        /* Reverse the list starting at the NEXT node after the slow node */
        ListNode* curr = slow->next;
        ListNode* rev = slow->next = nullptr;   // set slow->next and rev = null
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = rev;
            rev = curr;
            curr = temp;
        }

        /* Get each end of the linked list, first = head, second = end of list (front of reversed list)
         * Then alternate 
         */
        ListNode* first = head;
        ListNode* second = rev;
        while (second) {
            ListNode* temp = first->next;
            ListNode* temp2 = second->next;
            first->next = second; 
            second->next = temp;
            first = temp;
            second = temp2;
        }
    }
};
