/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void transversal(TreeNode*root, vector<int>&ans){

        if(root == NULL){
            return;
        }

        transversal(root->left,ans);
        transversal(root->right, ans);
        ans.push_back(root->val);

    }
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int>ans;
        transversal(root,ans);
        return ans;
        
    }
};