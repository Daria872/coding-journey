/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent_marking){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
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
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* ,TreeNode* >parent_marking;
        markParents(root,parent_marking);
        unordered_map<TreeNode* ,bool>visited;
        int curlevel=0;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        while(!q.empty()){
            int size=q.size();
            if(curlevel==k) break;
            curlevel++;
            for(int i=0;i<size;i++){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left && !visited[curr->left]){
                visited[curr->left]=true;
                q.push(curr->left);
            }
            if(curr->right && !visited[curr->right]){
                visited[curr->right]=true;
                q.push(curr->right);
            }
            if(parent_marking[curr] && !visited[parent_marking[curr]]){
                visited[parent_marking[curr]]=true;
                q.push(parent_marking[curr]);
            }
            }
        }
        vector<int>result;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            result.push_back(curr->val);
        }
        return result;
    }
};