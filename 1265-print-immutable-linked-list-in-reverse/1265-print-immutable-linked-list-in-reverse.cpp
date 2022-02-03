/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    
    void printLinkedListInReverse(ImmutableListNode* head) {
    
        if(head == NULL)                            return;
        
        if(head->getNext() == NULL) {
            // i.e head is the last node
            head->printValue();
            return;
        }
        
        printLinkedListInReverse(head->getNext());

        head->printValue();
        
        return;
    }
    
};