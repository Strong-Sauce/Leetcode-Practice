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
    bool hasCycle(ListNode *head) {
        if(!head) return 0;
        if(!head->next) return 0;
        if(!head->next->next) return 0;

        ListNode* slow = head;
        ListNode* fast = head;

        while(slow->next!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast->next!=NULL){ fast = fast->next;}

            if(slow == fast) return 1;
        }
        
        return 0;
    }
};