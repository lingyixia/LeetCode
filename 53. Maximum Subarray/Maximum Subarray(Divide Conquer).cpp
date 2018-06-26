#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums);
int maxSubDividArray(vector<int>& nums, int start, int end);
int crossMid(vector<int>& nums, int start, int end);
int main()
{
	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << maxSubArray(nums);
	return 0;
}

int maxSubArray(vector<int>& nums)
{
	return maxSubDividArray(nums, 0, nums.size() - 1);
}
int maxSubDividArray(vector<int>& nums, int start, int end)
{
	if (start == end)
	{
		return nums[start];
	}
	else
	{
		int mid = (start + end) / 2;
		int maxLeft = maxSubDividArray(nums, start, mid);
		int maxRight = maxSubDividArray(nums, mid + 1, end);
		int maxCross = crossMid(nums, start, end);
		return max(max(maxLeft,maxCross),maxRight);
	}
}
int crossMid(vector<int>& nums, int start, int end)
{
	int mid = (start + end) / 2;
	//mid以及左边最大值位置
	int maxLeft = INT_MIN;
	int maxTemp = 0;
	for (int i = mid; i >= start; i--)
	{
		maxTemp += nums[i];
		maxLeft = max(maxTemp, maxLeft);
	}
	//mid左边最大值位置
	int maxRight = INT_MIN;
	maxTemp = 0;
	for (int i = mid + 1; i <= end; i++)
	{
		maxTemp += nums[i];
		maxRight = max(maxTemp, maxRight);
	}
	return maxLeft + maxRight;
}