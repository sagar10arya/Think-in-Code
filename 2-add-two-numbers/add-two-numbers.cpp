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
    // time and space : O(max(n, m)), n:length of l2, m: length of l2
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry = 0;
        while(temp1 != NULL || temp2 != NULL)
        {
            int sum = carry;
            if(temp1) sum += temp1->val; // add from 1st list if available
            if(temp2) sum += temp2->val; // add from 2nd list if available
            ListNode* newNode = new ListNode(sum%10); // sum % 10 → digit
            carry = sum / 10;  // sum / 10 → carry

            curr->next = newNode;
            curr = curr->next;

            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }
        // If carry remains, add new node
        if(carry){
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }
        return dummy->next;
    }
};