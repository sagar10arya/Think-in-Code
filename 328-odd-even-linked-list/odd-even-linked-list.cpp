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
    // TC: O(2N), SC: O(N) --> brute force
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        vector<int> arr;  // stores nodes values
        // odd indices nodes
        while(temp != NULL && temp->next != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next->next; // move to next odd index
        }
        if(temp) arr.push_back(temp->val);  // If list length is odd, last odd node is missed in loop

        //even indices nodes
        temp = head->next; // start from second node (index 2)
        while(temp != NULL && temp->next != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next->next; // move to next even index
        }

        // overwrite original list
        temp = head;
        for(int i=0; i<arr.size(); i++)
        {
            temp->val = arr[i];
            temp = temp->next;
        }

        return head;
    }
};