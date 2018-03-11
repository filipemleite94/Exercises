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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return vector<vector<int>>();
        stack<vector<int>> st;
        stack<TreeNode*> current;
        stack<TreeNode*> next;
        current.push(root);
        while(!current.empty()){
            vector<int> v;
            while(!current.empty()){
                TreeNode* t = current.top();
                current.pop();
                v.push_back(t->val);
                if(t->left) next.push(t->left);
                if(t->right) next.push(t->right);
            }
            while(!next.empty()){
                current.push(next.top());
                next.pop();
            }
            st.push(v);
        }
        vector<vector<int>> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};