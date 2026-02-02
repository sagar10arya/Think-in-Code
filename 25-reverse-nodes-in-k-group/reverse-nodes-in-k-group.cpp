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
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = front;
        }
        return head;
    }
    // returns the kth node starting from temp
    // if fewer than k nodes exist, returns NULL
    ListNode* getKthNode(ListNode* temp, int k){
        k--;
        while(temp != NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
public:
    // TC: O(2N), SC: O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL; // last node of the previously reversed group
        while(temp != NULL){
            // Check if k nodes exist
            ListNode* kthNode = getKthNode(temp, k);
            if(kthNode == NULL){
                if(prevLast) prevLast->next = temp; // attach remaining as is if < k
                break;
            }
            // Detach group
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLinkedList(temp); // Reverse current group
            // Connect reversed group
            if(temp == head){
                head = kthNode;
            } else{
                prevLast->next = kthNode;
            }
            // go to next group
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};