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



class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* DFS(Node* node) {
        if(node == NULL) {
            return NULL;
        }
        if(visited.find(node) != visited.end()) {
            return visited[node];
        }
        Node* temp = new Node(node->val);
        visited[node] = temp;
        for(int i=0;i<node->neighbors.size();i++) {
            temp->neighbors.push_back(DFS(node->neighbors[i]));
            
        }
        return temp;
    }
    Node* cloneGraph(Node* node) {
        Node* newNode = DFS(node);
        return newNode;
    }
};