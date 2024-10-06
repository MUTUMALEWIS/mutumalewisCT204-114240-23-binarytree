#include <iostream>
#include <vector>
#include <stack>

using namespace std;
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder; 
        stack<TreeNode*> stack; 
        if (root == NULL) 
            return preorder;
        stack.push(root); 
        while (!stack.empty()) {
            TreeNode* curr = stack.top(); 
            stack.pop(); 
            preorder.push_back(curr->val); 
            if (curr->right != NULL)
                stack.push(curr->right);
            if (curr->left != NULL)
                stack.push(curr->left);
        }
        return preorder; 
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
    vector<int> result = solution.preorderTraversal(root);
    cout << "Preorder Traversal: ";
    for (size_t i = 0; i < result.size(); ++i) { 
        cout << result[i] << " ";  
    }
    cout << endl;
    delete root->left->left; 
    delete root->left;     
    delete root->right;     
    delete root;            

    return 0;                
}