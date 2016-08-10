#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> oneResult;
		if (s == "") {
			return result;
		}
		int size = s.size();
		partitionString(s, 0, size, result, oneResult);
		return result;
	}
private:
	void partitionString(string& s, int start, int& size, vector<vector<string>>& result, vector<string>& oneResult) {
		if (size == start) {
			result.push_back(oneResult);
			return;
		}
		if (size == start + 1) {
			string end = "";
			end += s[start];
			oneResult.push_back(end);
			result.push_back(oneResult);
			oneResult.pop_back();
			return;
		}
		string temp = "";
		for (int i = start; i < size; i++) {
			temp += s[i];
			if (isPalindrome(temp)) {
				oneResult.push_back(temp);
				partitionString(s, i + 1, size, result, oneResult);
				oneResult.pop_back();
			}
		}
	}

	bool isPalindrome(string& s) {
		int start = 0;
		int end = s.size() - 1;
		while (start < end) {
			if (s[start] != s[end]) {
				return false;
			}
			start++;end--;
		}
		return true;
	}
};

/*int main() {
	Solution s;
	s.partition("bb");
}*/