/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // move the longer list ahead by d nodes, then compare to find interesection
    ListNode* collisionPoint(ListNode* shorter, ListNode* longer, int d)
    {
        // move longer list ahead by d
        while(d && longer != NULL){
            d--;
            longer = longer->next;
        }
        // now t1 and t2 have same length so we can start comparing
        // move both pointers unitl the meet
        while(shorter != NULL && longer != NULL){
            if(shorter == longer) return shorter; // intersection found
            shorter = shorter->next;
            longer = longer->next;
        }
        return NULL;
    }
public:
    // Better
    // TC: O(N1+2N2), SC: O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        int n1 = 0, n2 = 0;
        while(t1 != NULL){
            n1++;
            t1 = t1->next;
        }
        while(t2 != NULL){
            n2++;
            t2 = t2->next;
        }

        if(n1 < n2){
            // A is shorter, B is longer
            return collisionPoint(headA, headB, n2 - n1);
        } else{
            // B is shorter, A is longer
            return collisionPoint(headB, headA, n1 - n2);
        }
    }
};