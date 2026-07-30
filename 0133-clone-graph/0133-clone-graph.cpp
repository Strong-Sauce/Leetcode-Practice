/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
// // dfs
// class Solution {
// public:
//     unordered_map<Node*, Node*> mp;  // Original -> Clone mapping

//     Node* cloneGraph(Node* node) {
//         if (!node) return nullptr;

//         if (mp.find(node) != mp.end())
//             return mp[node];  // already cloned

//         Node* clone = new Node(node->val);
//         mp[node] = clone;

//         for (Node* neighbor : node->neighbors) {
//             clone->neighbors.push_back(cloneGraph(neighbor));
//         }

//         return clone;
//     }
// };

// bfs
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> mp;
        queue<Node*> q;

        Node* clone = new Node(node->val);
        mp[node] = clone;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* neighbor : curr->neighbors) {
                if (mp.find(neighbor) == mp.end()) {
                    mp[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                mp[curr]->neighbors.push_back(mp[neighbor]);
            }
        }

        return clone;
    }
};