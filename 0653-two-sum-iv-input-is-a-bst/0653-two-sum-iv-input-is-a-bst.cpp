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
class BSTIterator{
    stack<TreeNode*>st;
    //reverse->false   next
    //reverse->true    before
    bool reverse=true;
    public:
        BSTIterator(TreeNode* root, bool isreverse){
            reverse=isreverse;
            pushAll(root);
        }
        bool hasnext(){
            return !st.empty();
        }
        int next(){
            TreeNode* node=st.top();
            st.pop();
            if(!reverse){//next{
                pushAll(node->right);
            }
            //before
            else {
                pushAll(node->left);
            }
            return node->val;
        }
    private:
        void pushAll(TreeNode* root){
            for(;root!=nullptr;){
                st.push(root);
                if(reverse==true)//before
                    root=root->right;
                else
                    root=root->left;
            }
        }
    };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        //create two iterators
        BSTIterator l(root,false);//this is next
        BSTIterator r(root,true);//this is before
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};