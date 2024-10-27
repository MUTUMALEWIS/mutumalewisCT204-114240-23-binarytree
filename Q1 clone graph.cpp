#include <iostream>
using namespace std;
#include <unordered_map>
#include <queue>
#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    node() : val(0), neighbors(std::vector<Node*>()) {}
    node(int _val) : val(_val), neighbors(std::vector<Node*>()) {}
    node(int _val, std::vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class Solution {
public:
    node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        std::unordered_map<Node*, Node*>queue;
        std::queue<Node*> queue;
        queue.push(node);
     
        clones[node] = new Node(node->val);

        while (!queue.empty()) {
            node* current = queue.front();
            queue.pop();

            for (Node* neighbor : current->neighbors) {
                if (clones.find(neighbor) == clones.end()) {
                    clones[neighbor] = new Node(neighbor->val);
                    queue.push(neighbor);
                }
                clone's neighbors
                Clones[current]->neighbors.push_back(clones[neighbor]);
            }
        }

        return clones[node];
    }
};

