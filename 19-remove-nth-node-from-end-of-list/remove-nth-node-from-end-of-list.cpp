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
    // TC: O(2n) --> brute force 2 passes
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        // count nodes
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        // if heads need to be deleled
        if(cnt == n){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // move to (cnt - n - 1)th node
        int res = cnt - n;
        temp = head;
        while(temp != NULL){
            res--;
            if(res == 0) break;
            temp = temp->next;
        }

        // delete nth node from end
        ListNode* deleteNode = temp->next;
        temp->next = temp->next->next;
        delete deleteNode;

        return head;
    }
};