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
    void deleteNode(ListNode* node) {
        int temp = node->next->val; // stores the value of next node
        node->val = temp; // overwrite current node's value, not deleteing just changing identity
        node->next = node->next->next; // skip the next node
    }
};