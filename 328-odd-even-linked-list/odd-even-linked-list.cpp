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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* odd = head; // odd pointer starts from first node
        ListNode* even = head->next;  // even pointer starts from second node
        ListNode* evenHead = head->next; // store even Head to attach later

        while(even != NULL && even->next != NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;  // attach odd->even

        return head;
    }
};