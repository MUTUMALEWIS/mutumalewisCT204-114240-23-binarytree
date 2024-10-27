#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

Int findCenter(int n, std::vector<std::pair<int, int>>& edges) {
    Std::unordered_map<int, int> degreeCount;
    For (auto edge : edges) {
        degreeCount[edge.first]++;
        degreeCount[edge.second]++;
    }
    
    For (auto& node : degreeCount) {
        If (node.second == n - 1) {
            Return node.first;
        }
    }
    
    Return -1; 
}

Int main() {
    Int n = 5;
    Std::vector<std::pair<int, int>> edges = {{1, 2}, {1, 3}, {1, 4}, {1, 5}};
    
    Int center = findCenter(n, edges);
    If (center != -1) {
        Std::cout << "The center of the star graph is node: " << center << std::endl;
    } else {
        Std::cout << "Invalid star graph." << std::endl;
    }
    
    Return 0;
}

