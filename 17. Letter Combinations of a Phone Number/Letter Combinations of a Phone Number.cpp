#include<iostream>
#include<algorithm>
using namespace std;
int length(char* str);
int main()
{
	char* str = "12345";
	cout<<length(str);
	return 0;
}
int length(char* str)
{
	if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return length(++str) + 1;
	}
}