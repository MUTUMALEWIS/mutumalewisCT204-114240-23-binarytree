#include <iostream>
#include <vector>

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
    void inOrder(TreeNode* root, vector<int> &ans) {
        if (!root) return; 
        inOrder(root->left, ans); 
        ans.push_back(root->val);  
        inOrder(root->right, ans); 
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;         
        inOrder(root, ans);      
        return ans;             
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
    vector<int> result = solution.inorderTraversal(root);
    cout << "Inorder Traversal: ";
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