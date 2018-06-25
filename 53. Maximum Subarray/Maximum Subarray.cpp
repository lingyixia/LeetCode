#include<iostream>
#include<vector>
using namespace std;
int maxSubArray(vector<int>& nums);
int main()
{
	vector<int> nums = {-2};
	cout << maxSubArray(nums);
	return 0;
}
int maxSubArray(vector<int>& nums)
{
	if (nums.size() == 1)
	{
		return nums[0];
	}
	int tempMaxPos = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		//ÿһ��ѭ�����������������������������Լ�֮ǰ����������Ƕ���
		if (nums[i-1]>0)
		{
			nums[i] += nums[i - 1];
		}
		if (nums[i]>nums[tempMaxPos])
		{
			tempMaxPos = i;
		}
	}
	return nums[tempMaxPos];
}