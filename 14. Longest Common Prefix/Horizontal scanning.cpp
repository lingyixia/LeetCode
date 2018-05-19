#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs);

int main()
{
	vector<string> strs = { "12345","1234" };
	cout << longestCommonPrefix(strs);
	return 0;
}
string longestCommonPrefix(vector<string>& strs)
{
	if (strs.empty())
	{
		return "";
	}
	string tempStr(*strs.begin());
	for (vector<string>::iterator iter = strs.begin() + 1; iter != strs.end(); iter++)
	{
		while (iter->substr(0, tempStr.size()) != tempStr)
		{
			tempStr = tempStr.substr(0, tempStr.size() - 1);
			if (tempStr.empty())
			{
				return "";
			}
		}
	}
	return tempStr;
}