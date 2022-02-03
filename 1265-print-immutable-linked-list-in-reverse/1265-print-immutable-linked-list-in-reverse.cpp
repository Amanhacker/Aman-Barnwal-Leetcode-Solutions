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
        
        ImmutableListNode* temp = head;
        
        if(temp->getNext() == NULL) {
            // i.e temp is the last node
            temp->printValue();
            return;
        }
        
        printLinkedListInReverse(temp->getNext());

        temp->printValue();
        
        return;
    }
    
};