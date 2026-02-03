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
    ListNode* findNthNode(ListNode* temp, int k)
    {
        int cnt = 1;
        while(temp != NULL){
            if(cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
public:
    // TC: O(N), SC: O(1)
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        int len = 1;
        ListNode* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }
        // normalize k
        if(k % len == 0) return head;
        k = k % len;

        tail->next = head; // make lits circular
        ListNode* newLastNode = findNthNode(head, len - k); // gives new tail
        // break the circle
        head = newLastNode->next;
        newLastNode->next = NULL;
        
        return head;
    }
};