
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        TreeNode* current(root);
        stack<TreeNode*> st;
        if(!current) return v;
        st.push(current);
        while(current->left){
            st.push(current->left);
            current = current->left;
        }
        while(!st.empty()){
            current = st.top();
            st.pop();
            v.push_back(current->val);
            if(current->right){
                st.push(current->right);
                current = current->right;
                while(current->left){
                    st.push(current->left);
                    current = current->left;
                }
            }
        }
        return v;
    }
};