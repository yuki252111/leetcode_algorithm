#include <iostream>
#include <vector>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		int sum = 0;
		vector<int> onePath;
		if (root) {
			sumPath(root, sum, onePath);
		}
		return sum;
	}
private:
	void sumPath(TreeNode* root, int& sum, vector<int>& onePath) {
		if (root->left == NULL && root -> right == NULL) {
			onePath.push_back(root->val);
			int temp = 0;
			int pathLen = onePath.size();
			for (int i = 0; i < pathLen; i++) {
				temp *= 10;
				temp += onePath[i];
			}
			sum += temp;
			onePath.pop_back();
			return;
		}
		onePath.push_back(root->val);
		if (root->left) {
			sumPath(root->left, sum, onePath);
		}
		if (root->right) {
			sumPath(root->right, sum, onePath);
		}
		onePath.pop_back();
	}
};

