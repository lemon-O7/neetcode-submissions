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
void swap(TreeNode* p) {
    TreeNode *temp;
    temp = p->left;
    p->left = p->right;
    p->right = temp;
}

void DFS(TreeNode* p) {
    if(p == NULL) {
        return;
    }

    swap(p);

    DFS(p->left);
    DFS(p->right);
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        DFS(root);
        return root;
    }
};