struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
bool SearchValue(TreeNode *node, int value){
	if(node==nullptr)
		return false;
	if(node->val==value)
		return true;
	if(node->val<value)
		return SearchValue(node->right, value);
	return SearchValue(node->left, value);
}

bool SearchValue(TreeNode *minNode, TreeNode *maxNode, int value){
	if(!minNode||!maxNode)
		return false;
	bool minBig{2*minNode->val > value}, maxSmall{2*maxNode->val < value};
	if(minBig) return SearchValue(minNode->left, maxNode, value);
	if(maxSmall) return SearchValue(minNode, maxNode->right, value);

	if(SearchValue(maxNode, value-minNode->val)) return true;
	if(SearchValue(minNode, value-maxNode->val)) return true;
	
	if(SearchValue(minNode->left, maxNode->right, value)) return true;
	if(SearchValue(minNode->right, maxNode->left, value)) return true;
	
	if(minNode->val + maxNode->val < value)	return SearchValue(minNode->right, maxNode->right, value);
	
	return SearchValue(minNode->left, maxNode->left, value);
}

bool SearchTree(TreeNode* root, int target){
	if(root==nullptr)	return false;
	int value = root->val;
	int sum = 2*value;
	if(sum==target)	return SearchValue(root->left, root->right, target);
	
	TreeNode copyRoot{*root};
	if(sum<target){
		copyRoot.right= nullptr;
		if(SearchValue(&copyRoot, root->right, target))	return true;
		return SearchTree(root->right, target);
	}
	
	copyRoot.left = nullptr;
	if(SearchValue(root->left, &copyRoot, target))	return true;
	return SearchTree(root->left, target);
}

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
		return SearchTree(root, k);
    }
};