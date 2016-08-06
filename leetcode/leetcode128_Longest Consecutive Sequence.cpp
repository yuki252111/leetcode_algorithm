#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		if (nums.size() <= 1) {
			return nums.size();
		}
		int max = 0;
		int temp = 1;
		int size = nums.size();
		for (int i = 1; i < size; i++) {
			if (nums[i] - nums[i - 1] == 0) {
				continue;
			}
			if (nums[i] - nums[i - 1] == 1) {
				temp++;
			}
			else {
				if (temp > max) {
					max = temp;
				}
				temp = 1;
			}
		}
		return temp > max? temp: max;
	}
};