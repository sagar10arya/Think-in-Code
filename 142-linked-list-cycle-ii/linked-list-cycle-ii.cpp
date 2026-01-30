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
    // brute force
    // TC: O(N), SC: O(N)
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_set<ListNode*> st;
        while(temp != NULL)
        {
            // lookup and insertion -> O(1) : average
            if(st.find(temp) != st.end()) return temp;
            st.insert(temp);
            temp = temp->next;
        }
        return NULL;
    }
};