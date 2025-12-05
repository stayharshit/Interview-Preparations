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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> q;
        int result = 0;
        if(!root){
            return result;
        }
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            TreeNode *leftNode;
            for(int i = 0;i<n;i++) {
                TreeNode *frontNode = q.front();
                q.pop();
                if(i == 0){
                    leftNode = frontNode;
                }
                if(frontNode -> left) {
                    q.push(frontNode -> left);
                }
                if(frontNode -> right) {
                    q.push(frontNode -> right);
                }
            }
            result = leftNode -> val;
        }
        return result;
    }
};