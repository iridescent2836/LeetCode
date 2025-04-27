#include "header.h"


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

// dfs
class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;

        if(visited.find(node)!=visited.end()) return visited[node];

        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        for(auto& neighbor: node->neighbors){
            cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }
};

// bfs
class Solution{
public:
    Node* cloneGraph(Node* node){
        if(node == nullptr) return node;

        unordered_map<Node*, Node*> visited;

        queue<Node*> qu;
        qu.push(node);
        visited[node] = new Node(node->val);
        while(!qu.empty()){
            auto n = qu.front();
            qu.pop();
            for(auto& neighbor: n->neighbors){
                if(visited.find(neighbor)==visited.end()){
                    visited[neighbor] = new Node(neighbor->val);
                    qu.push(neighbor);
                }
                visited[n]->neighbors.emplace_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};