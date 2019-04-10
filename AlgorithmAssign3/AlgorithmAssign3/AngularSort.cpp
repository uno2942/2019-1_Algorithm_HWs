/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Coord {
	long long x;
	long long y;
};

long long temp1;
long long temp2[100];
vector<Coord> ans[100];
Coord coord[1000000];

bool MyCompare(const Coord& c1, const Coord& c2) { // c1 is closer than c2 or c1 is near (0,1)
	long long temp = c1.x*c2.y - c2.x*c1.y;
	if (temp == 0) //c1 and c2 are on a line
	{
		if (c1.x*c2.x < 0)
		{
			if (c1.x > 0)
				return true;
			else
				return false;
		}
		if (abs(c1.x) > abs(c2.x))
			return false;
		else if (abs(c1.x) < abs(c2.x))
			return true;
		else // c1.x==c2.x
		{
			if (c1.y*c2.y < 0)
			{
				if (c1.y > 0)
					return true;
				else
					return false;
			}
			if (abs(c1.y) >= abs(c2.y))
				return false;
			else
				return true;
		}
	}
	else if (temp < 0) {
		if (c1.x >= 0)
			return true;
		else {
			if (c2.x >= 0)
				return false;
			else
				return true;
		}
	}
	else {//temp>0
		if (c1.x < 0)
			return false;
		else {
			if (c1.x == 0 && c1.y < 0)
				return false;
			else if (c1.x == 0 && c1.y > 0)
				return true;
			else // c1.x>0
			{
				if (c2.x < 0)
					return true;
				else
					return false;
			}
		}
	}
}
void merge(long long beg, long long mid, long long end) {
	long long pivotA = beg;
	long long pivotB = mid;
	long long i = 0;
	Coord* temp = new Coord[end - beg + 1];
	while (pivotA < mid && pivotB < end)
	{
		if (MyCompare(coord[pivotA], coord[pivotB]))
		{
			temp[i] = coord[pivotA];
			pivotA++;
		}
		else
		{
			temp[i] = coord[pivotB];
			pivotB++;
		}
		i++;
	}
	if (pivotA == mid)
	{
		while (pivotB < end)
		{
			temp[i] = coord[pivotB];
			pivotB++;
			i++;
		}
	}
	else {
		while (pivotA < mid)
		{
			temp[i] = coord[pivotA];
			pivotA++;
			i++;
		}
	}
	for (int j = 0; j < end - beg; j++) {
		coord[beg + j] = temp[j];
	}
	delete temp;
}
void Mymergesort(long long beg, long long end) {
	if (end - beg <= 1)
		return;
	int mid = (beg + end) / 2;
	Mymergesort(beg, mid);
	Mymergesort(mid, end);
	merge(beg, mid, end);
}
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		cin >> temp2[i];
		for (int j = 0; j < temp2[i]; j++) {
			cin >> coord[j].x >> coord[j].y;
		}
		Mymergesort(0, temp2[i]);
		for (int j = 0; j < temp2[i]; j++)
			ans[i].push_back(coord[j]);
	}
	for (int i = 0; i < temp1; i++) {
		for (int j = 0; j < temp2[i]; j++) {
			cout << ans[i][j].x << ' ' << ans[i][j].y << endl;
		}
	}
//	system("PAUSE");
	return 0;
}
*/