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
    int p=0;
    unordered_map<int,int> mp;
    TreeNode* Create(vector<int>& preorder,int l,int r) {
        if(l>r) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[p]);
        int pos = mp[preorder[p++]];

        root->left = Create(preorder, l, pos - 1);
        root->right = Create(preorder, pos + 1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int l=0,r=inorder.size()-1;

        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        TreeNode *root = Create(preorder,l,r);
        return root;
    }
};