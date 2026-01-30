/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Optimal
    // TC: O(N), SC: O(1)
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // detect cycle
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) break;
        }

        // no cycle
        if(fast == NULL || fast->next == NULL) return NULL;

        // find cycle start
        ListNode* entry = head;
        while(entry != slow){
            entry = entry->next;
            slow = slow->next;
        }
        return entry;
    }
};