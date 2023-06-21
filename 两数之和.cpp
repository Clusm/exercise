/*给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target的那两个整数并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 
*/


#include <vector>
#include<iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			if (m.count(target - nums[i]))
				return { m[target - nums[i]], i };
			m[nums[i]] = i;
		}
		return {};
	}
};

int main() {
	Solution sol;
	vector<int> nums = { 2, 7, 11, 15, 8, 5, 4 };
	int target = 9;
	vector<int> result = sol.twoSum(nums, target);
	if (!result.empty()) {
		cout << "Indices: " << result[0] << ", " << result[1] << endl;
	}
	else {
		cout << "No solution found!" << endl;
	}
	return 0;
}