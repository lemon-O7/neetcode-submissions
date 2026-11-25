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
    void order(TreeNode* a,TreeNode* b,bool flag) {
        if(!a) return ;
        if(flag) {
            int temp;
            temp = a->val;
            a->val = b->val;
            b->val = temp;
            order(a->left,b->right,false);
            order(a->right,b->left,false);
        }
        else {
            order(a->left,b->right,true);
            order(a->right,b->left,true);
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        order(root->left,root->right,true);
        return root;
    }
};