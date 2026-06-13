/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string ans;

    // Encodes a tree to a single string.
    void helpers(TreeNode* root) {
        if(root == NULL) {
            ans +="N,";
            return ;
        }
        ans += to_string(root->val)+",";
        helpers(root->left);
        helpers(root->right);
    }

    int i = 0;

    TreeNode* build(vector<string>& token) {
        if(token[i]=="N") {
            i++;
            return NULL;}
        TreeNode *node = new TreeNode();
        node->val = stoi(token[i++]);
        node->left = build(token);
        node->right = build(token);

        return node;
    }

    string serialize(TreeNode* root) {
        ans = "";
        helpers(root);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        TreeNode *root=build(tokens);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));