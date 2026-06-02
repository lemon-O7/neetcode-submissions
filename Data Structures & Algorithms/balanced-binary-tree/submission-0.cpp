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
    bool answer = true;
    int TreeHeight(TreeNode *p) {
        if(p==NULL) {
            return 0;
        }

        int left = TreeHeight(p->left);
        int right = TreeHeight(p->right);

        if(left - right > 1 || right - left >1) {
            answer = false;
        }

        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        TreeHeight(root);

        return answer;
    }
};