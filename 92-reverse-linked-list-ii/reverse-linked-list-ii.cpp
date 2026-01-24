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
    // TC: O(n)
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummy = new ListNode(-1, head); // dummy node to handle cases when left = 1
        ListNode* prev = dummy;
        // move prev -> (left - 1) position
        for(int i=1; i<left; i++)
        {
            prev = prev->next;
        }
        ListNode* curr = prev->next; // first node of sublist
        for(int i=1; i<=right-left; i++)
        {
            ListNode* temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }
        return dummy->next;
    }
};