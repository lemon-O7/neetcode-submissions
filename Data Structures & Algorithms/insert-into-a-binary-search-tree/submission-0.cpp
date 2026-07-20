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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *temp = root;

        if(root == NULL) {
            root = new TreeNode(val);
            return root;
        }

        while(temp != NULL) {

            if(val > temp->val) {
                if(temp->right == NULL) break;
                temp = temp->right;
            }
            else if(val < temp->val) {
                if(temp->left == NULL) break;
                temp = temp->left;
            }
        }   
        TreeNode *newNode = new TreeNode(val);
        if(temp->val > val) {
            temp->left = newNode;
        }
        else {
            temp->right = newNode;
        }
        newNode->left=newNode->right=NULL;
        return root;
    }
};