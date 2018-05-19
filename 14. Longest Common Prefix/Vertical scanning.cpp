#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs);

int main()
{
	vector<string> strs = {""};
	cout << longestCommonPrefix(strs);
	return 0;
}
string longestCommonPrefix(vector<string>& strs)
{
	if (strs.empty())
	{
		return "";
	}
	string str("");
	char ch;
	for (int pos = 0; pos < strs.begin()->size(); pos++)
	{
		ch = strs.begin()->at(pos);
		for (vector<string>::iterator iter = strs.begin() + 1; iter != strs.end(); iter++)
		{
			if (pos >= iter->size() || iter->at(pos) != ch)
			{
				return str;
			}
		}
		str += ch;
	}
	return str;
}