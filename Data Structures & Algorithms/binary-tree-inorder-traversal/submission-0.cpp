
class Solution {
public:
    vector<int> result;

    void Traversal(TreeNode* root) {
        if(root == NULL) return;
        Traversal(root->left);
        result.push_back(root->val);
        Traversal(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        Traversal(root);
        return result;
    }
};