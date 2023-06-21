/*����һ�������ظ����ֵ����� nums,���������п��ܵ�ȫ����,����� ������˳�� ���ش𰸡�*/
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) { //vector<vector<int>>����һ����ά���������������н��
		vector<vector<int>> res;
		permuteDFS(nums, 0, res);
		return res;
	}
	void permuteDFS(vector<int>& nums, int start, vector<vector<int>>& res) {
		if (start >= nums.size()) {
			res.push_back(nums);
			return;
		}
		for (int i = start; i < nums.size(); ++i) {
			swap(nums[start], nums[i]);
			permuteDFS(nums, start + 1, res);
			swap(nums[start], nums[i]);
		}
	}
};

int main() {
	Solution sol;
	vector<int> nums = { 1, 2, 3 ,5 ,8 ,9,12,14,16 };
	vector<vector<int>> res = sol.permute(nums);
	for (auto& v : res) {
		for (int num : v)
			cout << num << ' ';
		cout << '\n';
	}
	return 0;
}