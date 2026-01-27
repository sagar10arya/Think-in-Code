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
    // TC: O(length), SC: O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for(int i=0; i<n; i++) fast = fast->next;
        // if fast becomes null after moving n step --> node to delete is head itself
        if(fast == NULL){
            ListNode* newHead= head->next;
            delete head;
            return newHead;
        }
        ListNode* slow = head;
        // moving both pointers until the fast reaches the last node
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        // slow->next is the node to delete
        ListNode* deleteNthNode = slow->next;
        slow->next = slow->next->next;
        delete deleteNthNode;

        return head;
    }
};