#include<iostream>
#include<vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target);
int searchLeftPos(vector<int>& nums, int target, int low, int heigh);
int searchRightPos(vector<int>& nums, int target, int low, int heigh);
int main()
{
	vector<int> nums = { 0,0,0,1,1,2,3,4,5 };
	searchRightPos(nums,0, 0,8);
	return 0;
}
vector<int> searchRange(vector<int>& nums, int target)
{
	int low = 0, heigh = nums.size() - 1;
	int middle1 = 0, middle = 0, middle2 = 0;
	while (low <= heigh)
	{
		middle = (low + heigh) / 2;
		if (target == nums[low] && target == nums[heigh])
		{
			return vector<int>{ low, heigh };
		}
		else if (target > nums[middle])
		{
			low = middle + 1;
		}
		else if (target < nums[middle])
		{
			heigh = middle - 1;
		}
		else
		{
			middle = (low + heigh) / 2;
			int a = searchLeftPos(nums, target, low, middle);
			int b = searchRightPos(nums, target, middle, heigh);
			return vector<int>{a, b};
		}
	}
	return vector<int>{-1, -1};
}
int searchLeftPos(vector<int>& nums, int target, int low, int heigh)
{
	int middle = 0;
	while (low < heigh)
	{
		middle = (low + heigh) / 2;
		if (target == nums[middle])
		{
			heigh = middle;
		}
		else
		{
			low = middle + 1;
		}
	}
	return low;
}
int searchRightPos(vector<int>& nums, int target, int low, int heigh)
{
	int middle = 0;
	while (low <= heigh)
	{
		middle = (low + heigh) / 2;
		if (target == nums[middle])
		{
			low = middle+1;
		}
		else
		{
			heigh = middle - 1;
		}
	}
	return heigh;
}