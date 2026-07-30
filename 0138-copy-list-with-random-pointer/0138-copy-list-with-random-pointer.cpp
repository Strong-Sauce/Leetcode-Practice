/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* newHead = new Node(head->val);
        Node* temp = newHead;
        unordered_map<Node*, Node*> mp;
        mp[head] = newHead;
        while(head){
            if(!head->next) {
                temp->next = NULL;
            }
            else if(mp.find(head->next) != mp.end()){
                temp->next = mp[head->next];
            }
            else{
                temp->next = new Node(head->next->val);
                mp[head->next] = temp->next;
            }

            if(!head->random) {
                temp->random = NULL;
            }
            else if(mp.find(head->random) != mp.end()){
                temp->random = mp[head->random];
            }
            else{
                temp->random = new Node(head->random->val);
                mp[head->random] = temp->random;
            }

            temp = temp->next;
            head = head->next;
        }

        return newHead;
    }
};