#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
int maxPoints(vector<Point>& points);
int main()
{
	vector<Point> points = { Point(1,1),Point(3,2),Point(5,3),Point(4,1),Point(2,3),Point(1,4) };
	cout << maxPoints(points);
	return 0;
}
int maxPoints(vector<Point>& points)
{
	int max = 0;
	for (int i = 0; i < points.size(); i++)
	{
		if (max>=points.size()-i)
		{
			break;
		}
		int maxTemp = 0;
		map<double, int> temp;
		int duplicate = 1;
		for (int j = i + 1; j < points.size(); j++)
		{
			if ((points[j].x == points[i].x) && (points[j].y == points[i].y))
			{
				duplicate++;
			}
			else if (points[j].x - points[i].x == 0)
			{
				temp[INT_MAX] += 1;
				if (maxTemp < temp[INT_MAX])
				{
					maxTemp = temp[INT_MAX];
				}
			}
			else
			{
				double k = 10.0 * (points[j].y - points[i].y) / double(points[j].x - points[i].x);
				temp[k] += 1;
				if (maxTemp < temp[k])
				{
					maxTemp = temp[k];
				}
			}
		}
		maxTemp += duplicate;
		temp.clear();
		max = max > maxTemp ? max : maxTemp;
	}
	return max;
}