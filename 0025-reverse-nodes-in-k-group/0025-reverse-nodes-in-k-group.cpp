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
    // pair<ListNode* ,ListNode* > rev(ListNode* head, int k){
    //     ListNode*  curr = head;
    //     ListNode*  prev = head;
    //     int a = k;
    //     while(a){
    //         prev = prev->next;
    //         a--;
    //     }
    //     while(curr && k){
    //         ListNode*  next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //         k--;
    //     }
    //     return curr
    // }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while (true) {
            // Find the kth node from groupPrev
            ListNode* kth = groupPrev;
            for (int i = 0; i < k && kth; ++i) {
                kth = kth->next;
            }
            if (!kth) break; // Less than k nodes left

            ListNode* groupNext = kth->next;

            // Reverse k nodes
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect previous group to reversed group
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        return dummy->next;
    }
};