#include <string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool SearchValue(TreeNode *minCurrent, TreeNode* maxCurrent, int target){
	if(minCurrent==nullptr||maxCurrent==nullptr)
		return false;
	bool ans;
	int sum = minCurrent->val + maxCurrent->val;
	if(sum>target){
		if(SearchValue(minCurrent->left, maxCurrent, target))
			return true;
		return SearchValue(minCurrent, maxCurrent->left, target);
	}
	if(sum<target){
		if(SearchValue(minCurrent->right, maxCurrent, target))
			return true;
		return SearchValue(minCurrent, maxCurrent->right, target);
	}
	return true;
}
 
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
		if(root == nullptr)
			return false;
		int sum = root->val + root->val;
		if(sum==k){
			return SearchValue(root->left, root->right, k);
		}
		TreeNode copyRoot{*root};
		if(sum>k){
			copyRoot.left = nullptr;
			return SearchValue(root->left, &copyRoot, k);
		}
		if(sum<k){
			copyRoot.right = nullptr;
			return SearchValue(&copyRoot, root->right, k);
		}
		return false;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        bool ret = Solution().findTarget(root, k);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}