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
    // TC: O(N + N/2), SC: O(1)
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        int cnt = 0;
        ListNode* temp = head;
        // count nodes
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        int middleNodeBefore = cnt / 2; // one node before middle
        temp = head;
        while(temp != NULL){
            middleNodeBefore--;
            if(middleNodeBefore == 0)
            {
                ListNode* middleNode = temp->next;
                temp->next = temp->next->next;
                delete middleNode;
            }
            temp = temp->next;
        }

        return head;
    }
};