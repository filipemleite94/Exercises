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
    bool areTreesSymmetric(TreeNode* root1, TreeNode* root2){
        if(!root1||!root2)
            return !root1==!root2;
        return root1->val==root2->val&&areTreesSymmetric(root1->left, root2->right)&&areTreesSymmetric(root1->right, root2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return areTreesSymmetric(root->left, root->right);
    }
};