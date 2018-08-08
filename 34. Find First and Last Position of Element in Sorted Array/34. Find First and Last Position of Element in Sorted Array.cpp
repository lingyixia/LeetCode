#include<iostream>
#include<vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target);
int main()
{
	vector<int> nums = { 5,7,7,8,8,10 };
	nums = searchRange(nums, 8);
	return 0;
}
vector<int> searchRange(vector<int>& nums, int target)
{
	int low = 0;
	int heigh = nums.size() - 1;
	int middle = 0;
	while (low <= heigh)
	{
		middle = (low + heigh) / 2;
		if (target <= nums[middle])
		{
			heigh = middle - 1;
		}
		else
		{
			low = middle + 1;
		}
	}
	if (low == nums.size() || nums[low] != target)
	{
		return vector<int>{-1, -1};
	}
	vector<int> ret(2, low);
	heigh = nums.size() - 1;
	while (low <= heigh)
	{
		middle = (low + heigh) / 2;
		if (target < nums[middle])
		{
			heigh = middle - 1;
		}
		else
		{
			low = middle + 1;
		}
	}
	ret[1] = heigh;
	return ret;
}