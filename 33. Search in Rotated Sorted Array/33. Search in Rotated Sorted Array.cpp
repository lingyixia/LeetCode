#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target);
int main()
{
	vector<int> nums = {3,1};
	cout<<search(nums, 1);
	return 0;
}
int search(vector<int>& nums, int target)
{
	int low = 0;
	int height = nums.size() - 1;
	int middle = 0;
	while (low <= height)
	{
		middle = (low + height) / 2;
		if (target == nums[middle])
		{
			return middle;
		}
		else
		{
			if (nums[low] <= nums[middle])
			{
				if (nums[low] <= target && target<nums[middle])
				{
					height = middle - 1;
				}
				else
				{
					low = middle + 1;
				}
			}
			if(nums[middle]<=nums[height])
			{
				if (target <= nums[height] && target >nums[middle])
				{
					low = middle + 1;
				}
				else
				{
					height = middle - 1;
				}
			}
		}
	}
	return -1;
}