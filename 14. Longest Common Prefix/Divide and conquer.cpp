#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs);
string longestCommonPrefix(vector<string>& strs, unsigned int start, unsigned int end);
string commonPrefix(string left, string right);

int main()
{
	vector<string> strs = { ""};
	cout << longestCommonPrefix(strs);
	return 0;
}
string longestCommonPrefix(vector<string>& strs)
{
	if (strs.empty())
	{
		return "";
	}
	return longestCommonPrefix(strs, 0, strs.size() - 1);
}
string longestCommonPrefix(vector<string>& strs, unsigned int start, unsigned int end)
{
	if (start == end)
	{
		return strs[start];
	}
	else
	{
		unsigned int mid = (start + end) / 2;
		string left = longestCommonPrefix(strs, start, mid);
		string right = longestCommonPrefix(strs, mid + 1, end);
		return commonPrefix(left, right);
	}
}
string commonPrefix(string left, string right)
{
	string str("");
	unsigned int pos = 0;
	for (unsigned int pos = 0; pos < left.size() && pos < right.size(); pos++)
	{
		if (left[pos]!=right[pos])
		{
			return str;
		}
		str += left[pos];
	}
	return str;
}