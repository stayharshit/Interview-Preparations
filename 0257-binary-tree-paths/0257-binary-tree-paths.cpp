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
public:
    void binaryTreePathsHelper(TreeNode *root, vector<string> &v, string str) {
        if(!root)
            return;
        str += to_string(root->val);
        if(!root->left and !root->right){
            v.push_back(str);
        }
        str += "->";
        if(root->left)
            binaryTreePathsHelper(root->left,v,str);
        if(root->right)
            binaryTreePathsHelper(root->right,v, str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root){
            return {};
        }
        string str;
        vector<string> v;
        binaryTreePathsHelper(root, v, str);
        return v;
    }
};