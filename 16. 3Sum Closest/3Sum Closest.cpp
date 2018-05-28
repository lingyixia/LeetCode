#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int threeSumClosest(vector<int>& nums, int target);

int main()
{
	vector<int> array = { -3,-2,-5,3,-4 };
	cout << threeSumClosest(array, -1);
	return 0;
}

int threeSumClosest(vector<int>& nums, int target)
{
	bool ifChange = false;
	int begin, end;
	int sum = nums[0] + nums[1] + nums[2];
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 2; i++)
	{
		begin = i + 1;
		end = nums.size() - 1;
		while (begin < end)
		{
			int temp_sum = nums[i] + nums[begin] + nums[end];
			if (temp_sum < target)
			{
				begin++;
			}
			else if (temp_sum > target)
			{
				end--;
			}
			else
			{
				return target;
			}
			if (abs(target - temp_sum) < abs(target - sum))
			{
				sum = temp_sum;
			}
		}
	}
	return sum;
}