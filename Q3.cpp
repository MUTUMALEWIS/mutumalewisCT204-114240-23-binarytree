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
    void solve(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return; 
        solve(root->left, ans);   
        solve(root->right, ans);  
        ans.push_back(root->val); 
    }
	   vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;          
        solve(root, ans);        
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
    vector<int> result = solution.postorderTraversal(root);
    cout << "Postorder Traversal: ";
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