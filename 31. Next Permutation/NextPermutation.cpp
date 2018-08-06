#include<iostream>
#include<vector>
using namespace std;
void nextPermutation(vector<int>& nums);
int main()
{
	vector<int> nums = { 1,1,5 };
	nextPermutation(nums);
	return 0;
}
void nextPermutation(vector<int>& nums)
{
	int i = nums.size() - 2;
	int j = 0;
	while (i >= 0 && nums[i] >= nums[i + 1])
	{
		i--;
	}
	if (i>=0)
	{
		j = i + 1;
		while (j < nums.size() && nums[j] > nums[i])
		{
			j++;
		}
		j = j - 1;
		nums[i] = nums[i] ^ nums[j];
		nums[j] = nums[i] ^ nums[j];
		nums[i] = nums[i] ^ nums[j];
	}
	i = i + 1;
	j = nums.size() - 1;
	while (j > i)
	{
		nums[i] = nums[i] ^ nums[j];
		nums[j] = nums[i] ^ nums[j];
		nums[i] = nums[i] ^ nums[j];
		i++;
		j--;
	}
}