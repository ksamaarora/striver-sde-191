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
        // Method 1: Brute Force
        // TC and SC: O(1)
        node->val=node->next->val;
        node->next=node->next->next;
    }
};

// Note: If head was given then code would have been : 
class Solution {
public:
    void deleteNode(ListNode* head, ListNode* node) {
        if(head==node){
            ListNode* temp=head->next;
            delete head;
            return temp;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* curr=head;
        while(curr!=NULL){
            if(curr==node){
                prev->next=curr->next;
                delete curr;
                break;
            }
            prev=curr;
            curr=curr->next;
        }
        ListNode* newHead=dummy->next; // store the updated head
        delete dummy; // free the dummy node
        return newHead; // return the updated head
    }
};