#include <iostream>
#include <algorithm>
#include <utility> 
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
	};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkBalanceAndHeight(root).first;
    }

private:
    std::pair<bool, int> checkBalanceAndHeight(TreeNode* node) {
        if (!node) {
            return std::make_pair(true, 0); 
        }

        std::pair<bool, int> left = checkBalanceAndHeight(node->left);  
        std::pair<bool, int> right = checkBalanceAndHeight(node->right); 
        bool balanced = left.first && right.first && std::abs(left.second - right.second) <= 1;
        int height = std::max(left.second, right.second) + 1;

        return std::make_pair(balanced, height);
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    bool result = solution.isBalanced(root);
    
    std::cout << "The binary tree is " << (result ? "balanced" : "not balanced") << std::endl;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}