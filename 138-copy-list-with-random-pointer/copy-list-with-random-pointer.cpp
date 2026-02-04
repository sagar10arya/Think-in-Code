/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // TC: O(3N) ==> O(N)
    // SC: O(1)
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        // step 1: insert copy nodes in between
        while(temp != NULL)
        {
            Node* copyNode= new Node(temp->val); // create copy
            copyNode->next = temp->next;         // copy points to original next
            temp->next = copyNode;               // original points to copy
            temp = temp->next->next;             // move to next original node
        }
        
        // step2: connect random pointers
        temp = head;
        while(temp != NULL)
        {
            Node* copyNode = temp->next;
            // if original node has random, copy should point to copy of that random
            if(temp->random) copyNode->random = temp->random->next;
            else copyNode->random = NULL;
            temp = temp->next->next;
        }

        // step3: connect next pointers
        temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        while(temp != NULL){
            // attach copied node to result list
            res->next = temp->next;
            res = res->next;

            // disconnecting and going back to inital state of LL
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }
};