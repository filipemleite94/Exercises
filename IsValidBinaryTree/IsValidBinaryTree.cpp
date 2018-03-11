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
private:
    bool isValidNode(TreeNode *node, long long min, long long max){
        if(!node) return true;
        if(node->val>min && node->val<max && isValidNode(node->left, min, node->val) && isValidNode(node->right, node->val, max))
            return true;
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidNode(root, INT_MIN - 1ll, INT_MAX+1ll);
    }
};