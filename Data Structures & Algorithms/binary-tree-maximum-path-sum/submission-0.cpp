class Solution {
public:
    int ans=INT_MIN;

    int SumDown(TreeNode* root){
        if(root== NULL) {
            return 0;
        }

        int left = SumDown(root->left);
        int right = SumDown(root->right);
        ans = max(ans, root->val + max(0,left) + max(0,right));

        return root->val + max(0, max(left, right));
    }

    int maxPathSum(TreeNode* root) {
        SumDown(root);
        return ans;
    }
};