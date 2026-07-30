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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0 || !head->next) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        k = k % len;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        for(int i=0; i<k; i++){
            fast = fast->next;
        }

        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        if(!fast->next) fast->next = head;

        head = slow->next;
        slow->next = NULL;

        dummy->next =NULL;
        return head;
    }
};