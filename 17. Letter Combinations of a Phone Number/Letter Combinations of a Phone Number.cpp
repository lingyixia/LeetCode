#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<string> letterCombinations(string digits);

int main()
{
	letterCombinations("23");
	return 0;
}

vector<string> letterCombinations(string digits)
{
	vector<string> retCombine;
	if (digits.empty())
	{
		return retCombine;
	}
	map<char, string> dial = { { '2',"abc" },{ '3',"def" },{ '4',"ghi" },{ '5',"jkl" },{ '6',"mno" },{ '7',"pqrs" },{ '8',"tuv", },{ '9',"wxyz" } };
	int allSteps = 1;
	for (int i = 0; i < digits.size(); i++)
	{
		allSteps *= dial[digits[i]].size();
	}
	for (int i = 0; i < allSteps; i++)
	{
		int step = allSteps;
		string tempStr = "";
		for (int j = 0; j < digits.size(); j++)
		{
			step /= dial[digits[j]].size();
			int pos = i / step % dial[digits[j]].size();
			tempStr += dial[digits[j]][pos];
		}
		retCombine.push_back(tempStr);
		tempStr = "";
	}
	return retCombine;
}