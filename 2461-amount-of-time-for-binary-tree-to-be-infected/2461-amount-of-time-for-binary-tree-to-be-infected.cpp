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
    int maxTime(TreeNode* root,map<TreeNode*,TreeNode*>&parent_marking, TreeNode* targetNode){
        queue<TreeNode*>q;
        int maxi=0;
        map<TreeNode*,int>visited;
        q.push(targetNode);
        visited[targetNode]=1;
        while(!q.empty()){
            int size=q.size();
            int fl=0;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    fl=1;
                    visited[curr->left]=1;
                    q.push(curr->left);
                }
                if(curr->right && !visited[curr->right]){
                    fl=1;
                    visited[curr->right]=1;
                    q.push(curr->right);
                }
                if(parent_marking[curr] && !visited[parent_marking[curr]]){
                    fl=1;
                    visited[parent_marking[curr]]=1;
                    q.push(parent_marking[curr]);
                }
            }
            if(fl) maxi++;
        }
        return maxi;
    }
    TreeNode* markParent(TreeNode* root,map<TreeNode*,TreeNode*>&parent_marking, int start){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* res=nullptr;
        while(!q.empty()){
            TreeNode* curr=q.front();
            if(curr->val==start){
                res=curr;
            }
            q.pop();
            if(curr->left){
                parent_marking[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_marking[curr->right]=curr;
                q.push(curr->right);
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>parent_marking;
        markParent(root,parent_marking,start);
        TreeNode* targetNode=markParent(root,parent_marking,start);
        int maxi=maxTime(root,parent_marking,targetNode);
        return maxi;
    }
};