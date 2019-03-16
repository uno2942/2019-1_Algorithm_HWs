/*#include<iostream>
#include<algorithm>
using namespace std;
struct Coord {
	long long x;
	long long y;
};
int temp1;
int temp2[50];
long long ans[50];
Coord dat[100000];
Coord temp[100000];
bool Comp(Coord a, Coord b) {
	if (a.x < b.x)
		return true;
	else
		return false;
}
bool Compy(Coord a, Coord b) {
	if (a.y < b.y)
		return true;
	else
		return false;
}
long long CalcDist(Coord a, Coord b) {
	return abs(a.x - b.x)+abs(a.y-b.y);
}
long long FindShortest_rec(Coord* dat, int beg, int fin) {
	if (fin - beg == 2)
		return CalcDist(dat[fin - 1], dat[beg]);
	else
	{
		long long a = FindShortest_rec(dat, beg, (beg + fin + 1) / 2);
		long long b = FindShortest_rec(dat, (beg + fin - 1) / 2, fin);
		long long preans = min(a, b);
		int mid = (beg + fin) / 2;
		int low = mid;
		int high = mid;
		while (low > beg && (dat[low].x - dat[mid].x < preans))
			low--;
		while (high < fin && dat[high].x - dat[mid].x < preans)
			high++;
		for (int i = low; i < high; i++) {
			temp[i] = dat[i];
		}
		sort(temp + low, temp + high, Compy);

		for (int i = low; i < high; i++)
		{
			if (low < i && (temp[i].y - temp[i - 1].y) < preans)
			{
				for (int j = max(i - 6, low); j < i; j++)
				{
					long long tempans = CalcDist(temp[i], temp[j]);
					if (tempans < preans)
						preans = tempans;
				}
			}
			if (high > i && (temp[i + 1].y - temp[i].y) < preans)
			{
				for (int j = i + 1; j < min(high, i + 6); j++)
				{
					long long tempans = CalcDist(temp[i], temp[j]);
					if (tempans < preans)
						preans = tempans;
				}
			}

		}
		return preans;
	}
}
long long FindShortest(Coord* dat, int n) {
	return FindShortest_rec(dat, 0, n);
}
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		cin >> temp2[i];
		for (int j = 0; j < temp2[i]; j++) {
			cin >> dat[j].x >> dat[j].y;
		}
		sort(dat, dat + temp2[i], Comp);
		ans[i] = FindShortest(dat, temp2[i]);
	}
	for (int i = 0; i < temp1; i++)
		cout << ans[i] << endl;
//	system("PAUSE");
	return 0;
}
*/