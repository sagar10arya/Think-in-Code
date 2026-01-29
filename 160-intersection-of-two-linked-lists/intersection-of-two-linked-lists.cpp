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
    // Brute force
    // TC: O(n log n), n=lenght of listA+listB
    // SC: O(N)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> mpp;
        ListNode* temp = headA;
        // store all nodes of listA
        while(temp != NULL){
            mpp[temp]++;
            temp = temp->next;
        }
        // traverse  listB and check intersection
        temp = headB;
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()) return temp;
            temp = temp->next;
        }
        return NULL; // no intersection
    }
};