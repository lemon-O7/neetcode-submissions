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
    bool compare(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL) {
            return 1;
        }
        if (root == NULL || subRoot == NULL) {
            return 0;
        }
    
        if(root->val != subRoot->val) {
            return 0;
        }
        bool left = compare(root->left,subRoot->left);
        bool right = compare(root->right,subRoot->right);
          
        return left && right;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL ) {
            return 0;
        }
        bool ans = 0;
        if(root->val == subRoot->val) {
        ans = compare(root,subRoot);
        }
    
        bool left = isSubtree(root->left,subRoot);
        bool right = isSubtree(root->right,subRoot);

        return ans || left || right;
    }
};