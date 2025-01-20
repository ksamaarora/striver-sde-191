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
    ListNode* reverseList(ListNode* head) {
        // Method 1: Brute force - changing the arrow directions to opposite by keeping a track of the next element
        // TC:O(N) SC:O(1)
        ListNode* prev=NULL;
        ListNode* temp=head;
        if(temp==NULL || temp->next==NULL){
            return head;
        }
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev; // as this would be the new head now 

        // Method 2: Recursive method
        // TC:O(n) SC: O(n)
        if(head==NULL || head->next==NULL) return head;
        ListNode* newHead=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }
};