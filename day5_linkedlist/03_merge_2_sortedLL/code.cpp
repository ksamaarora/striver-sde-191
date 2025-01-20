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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Method 1: Brute Force (New list)
        // IMP 
        // TC:O(n1+n2) SC:O(n1+n2)
        ListNode dummy;
        ListNode* d=&dummy;

        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                d->next=list1;
                list1=list1->next;
            }
            else{
                d->next=list2;
                list2=list2->next;
            }
            d=d->next;
        }

        if(list1!=NULL){
            d->next=list1;
        }
        else{
            d->next=list2;
        }
        return dummy.next;

        // Method 2: In Place
        // explanation: l1 point to the list which has the first element small and l2 to the other list 
        // TC:O(N1+N2)
        // SC:O(1)
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1->val>list2->val) std::swap(list1,list2);
        ListNode* res=list1; // remeber head of l1 
        while(list1!=NULL && list2!=NULL){
            ListNode* temp=NULL;
            while(list1!=NULL && list1->val<=list2->val){
                temp=list1;
                list1=list1->next;
            }
            temp->next=list2;
            std::swap(list1,list2);
        }
        return res;
    }
};