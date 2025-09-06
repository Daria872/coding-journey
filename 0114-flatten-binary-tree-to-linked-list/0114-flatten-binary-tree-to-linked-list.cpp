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
    void flattenNode(TreeNode* root, TreeNode*& prev){
        if(root==nullptr)
            return;
        flattenNode(root->right,prev);
        flattenNode(root->left,prev);
        root->right=prev;
        root->left=nullptr;
        prev=root;
    }
    void flatten(TreeNode* root) {
        TreeNode* prev=nullptr;
        flattenNode(root,prev);
    }
};