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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        if(!head->next) return NULL;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp = dummy;
        int len = 0;
        while(temp->next){
            temp = temp->next;
            len++;
        }
        temp = dummy;

        k = len-k;

        for(int i=1; i<=k; i++){
            temp = temp->next;
        }
        if(temp->next)
            temp->next = temp->next->next;

        return dummy->next;
    }
};