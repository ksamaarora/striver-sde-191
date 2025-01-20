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
    ListNode* middleNode(ListNode* head) {
        // Method 1: Brute force 
        // TC: O(N+ N/2), SC:O(1)
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        int middleNode=(cnt/2);
        cnt=0;
        temp=head;
        while(temp!=NULL){
            if(cnt==middleNode){
                return temp;
            }
            cnt++;
            temp=temp->next;
        }
        return NULL;

        // Method 2: Optimal Approach - TORTOISE AND HAIR METHOD (IMPORTANT)
        // Intiialize slow and fast to head 
        // Move slow tortoise by 1 and fast tortoise by 2
        // The moment the fast tortoise reached either the last node or beyond that (i.e. NULL), the slow tortoise must have reached the middle node 
        // TC:O(N/2) , SC:O(1)
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;  
   }
};