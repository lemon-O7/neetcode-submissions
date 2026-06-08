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
    int ans = 0;

    void dfs(TreeNode* root, int currmax) {
        if(root == NULL) {
            return ;
        }

        if(currmax<=root->val) {
            ans++;
            
        }
        currmax = max(currmax, root->val);
        
        dfs(root->left,currmax);
        dfs(root->right,currmax);

    }

    int goodNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        dfs(root,root->val);
        return ans;
    }
};