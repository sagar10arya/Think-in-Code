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
    // TC: O(N), SC: O(1)
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL; // last node that is unique and kept
        while(curr != NULL)
        {
            // duplicate group
            if(curr->next != NULL && curr->val == curr->next->val){
                int val = curr->val;
                while(curr != NULL && curr->val == val) curr = curr->next;
                if(prev != NULL) prev->next = curr; // connect last valid node to next unqiue
                else head = curr; // duplicate goup was head
            }
            // no duplicates 
            else{
                prev= curr;
                curr = curr->next;
            }
        }
        return head;
    }
};