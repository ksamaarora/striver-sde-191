class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Method 1: Brute Force 
        // TC: O(N1 + (N1-n))
        // SC: O(1)
        ListNode* dummy = new ListNode();
        dummy->next=head; // or just write ListNode* dummy = new ListNode(0,head);
        ListNode* temp = dummy;
        int size = 0;

        // Calculate the size of the list
        while (temp->next != NULL) {
            temp = temp->next;
            size++;
        }

        // Calculate the position to stop before the node to remove
        int delete_track = size - n;
        temp = dummy;

        // Traverse to the node before the one to be deleted
        for (int i = 0; i < delete_track; i++) {
            temp = temp->next;
        }

        // Remove the node
        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;

        // Return the new head
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;

        // Method 2: Optimal Solution
        // Slow and Fast Pointer 
        // TC:O(N)
        // SC:O(1)
        ListNode* start=new ListNode();
        start->next=head;
        ListNode* fast=start;
        ListNode* slow=start;

        for(int i=1; i<=n; i++){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return start->next;
    }
};
