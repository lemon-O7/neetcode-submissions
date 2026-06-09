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
    bool DFS(TreeNode* root, long long int high, long long int low) {
        if(root == NULL) {
            return true;
        }

        if(low >= root->val || high <= root->val) {
            return false;
        }

        
        bool left = DFS(root->left,root->val,low);
        bool right = DFS(root->right,high,root->val);

        return left && right ;
    }

    bool isValidBST(TreeNode* root) {

        return DFS(root,LLONG_MAX,LLONG_MIN);
    }
};