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
    // TC: O(N + N/2), SC: O(1) --> Brute
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        int middleNode = (cnt/2) + 1;
        temp = head;
        while(temp != NULL)
        {
            middleNode--;
            if(middleNode == 0) break;
            temp = temp->next;
        }
        return temp;
    }
};