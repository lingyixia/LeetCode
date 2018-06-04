#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums);
int main()
{
	vector<int> nums = {};
	removeDuplicates(nums);
	return 0;
}
int removeDuplicates(vector<int>& nums) {
	int pos = 0;
	for (int index = 1; index < nums.size(); index++)
	{
		if (nums[index] != nums[pos])
		{
			nums[++pos] = nums[index];
		}
	}
	return ++pos;
}