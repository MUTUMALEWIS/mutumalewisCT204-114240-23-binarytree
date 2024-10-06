#include <iostream>
#include <climits> 
#include <algorithm> 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {} 
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPath(TreeNode* root, int &maxi) {
        if (root == NULL) return 0;

        int lh = std::max(0, maxPath(root->left, maxi)); 
        int rh = std::max(0, maxPath(root->right, maxi)); 
        maxi = std::max(maxi, lh + rh + root->val); 

        return root->val + std::max(lh, rh); 
		    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root, maxi);
        return maxi;
    }
};
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    Solution solution;
    int result = solution.maxPathSum(root);
    std::cout << "Maximum Path Sum: " << result << std::endl;
    delete root->left->left;
    delete root->left;       
    delete root->right;      
    delete root;             

    return 0;
}