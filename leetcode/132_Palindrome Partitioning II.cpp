#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		int size = s.size();
		if (size <= 1 || isPalindrome(s)) {
			return 0;
		}
		int* minCut = new int[size + 1];
		minCut[0] = minCut[1] = 0;
		for (int i = 2; i <= size; i++) {
			minCut[i] = minCut[i - 1] + 1;
			for (int j = i - 2; j >= 0; j--) {
				string temp = s.substr(j, i - j);
				if (isPalindrome(temp)) {
					if (j == 0) {
						minCut[i] = 0;
					}
					else if (minCut[j] + 1 < minCut[i]) {
						minCut[i] = minCut[j] + 1;
					}
				}
			}
		}
		return minCut[size];
	}
private:
	bool isPalindrome(string& s) {
		int size = s.size();
		if (size <= 1) {
			return true;
		}
		int start = 0, end = size - 1;
		while (start < end) {
			if (s[start] != s[end]) {
				return false;
			}
			start++;end--;
		}
		return true;
	}
};

//int main() {
//	Solution s;
//	int result = s.minCut("aaabaa");
//	cout << result << endl;
//}