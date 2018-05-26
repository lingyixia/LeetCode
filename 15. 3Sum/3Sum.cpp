#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);

int main()
{
	vector<int> nums = { -2,0,0,2,2 };
	threeSum(nums);
	return 0;
}
vector<vector<int>> threeSum(vector<int>& nums)
{
	std::sort(nums.begin(), nums.end());
	vector<vector<int>> retVector;
	vector<int> tempVector;
	int target, begin, end;
	for (int i = 0; i < (int)nums.size() - 2 && nums[i] <= 0; i++)
	{
		if (i == 0 || nums[i] != nums[i - 1])
		{
			target = -nums[i];
			begin = i + 1;
			end = nums.size() - 1;
			while (begin < end)
			{
				if (nums[begin] + nums[end] < target)
				{
					begin++;
				}
				else if (nums[begin] + nums[end] > target)
				{
					end--;
				}
				else
				{
					tempVector.push_back(nums[i]);
					tempVector.push_back(nums[begin]);
					tempVector.push_back(nums[end]);
					retVector.push_back(tempVector);
					tempVector.clear();
					do
					{
						begin++;
						end--;
					} while (begin < end && (nums[begin] == nums[begin - 1] && nums[end] == nums[end + 1]));
				}
			}
		}
	}
	return retVector;
}