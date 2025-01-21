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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Method 1: Brute Force 
        // TC: O(max(N1, N2)), where N1 and N2 are the number of nodes in l1 and l2 respectively
        // SC: O(max(N1, N2)), as the size of the output list depends on the longer input list
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int sum=carry; // Start with the carry from the previous step
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            carry=sum/10; // Update carry
            temp->next=new ListNode(sum%10); // Append the new digit
            temp=temp->next; // move to next node 
        }
        return dummy->next;

        // Method 2: Try a method that does the process in place without using extra SC
        
    }
};