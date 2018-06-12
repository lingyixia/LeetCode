/*多列表递归实现排列组合
*/
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> globalVec;
vector<vector<int>> lists = { {0,1,2},{3,4,5},{6,7,8,9} };
vector<vector<int>> retLists;
void fun(vector<int> currentCom, int order);
int main()
{
	vector<int> currentCom;
	fun(currentCom, 0);
	return 0;
}
void fun(vector<int> currentCom, int order)
{
	if (order == lists.size())
	{
		retLists.push_back(currentCom);
		return;
	}
	for (int i = 0; i < lists[order].size(); i++)
	{
		currentCom.push_back(lists[order][i]);
		fun(currentCom, order + 1);
		currentCom.pop_back();
	}
}