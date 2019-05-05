#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long temp1;
long long N;
long long x, y;
vector<pair<long long, long long>> points;
long long ans[101];
bool comparey(pair<long long, long long> p1, pair<long long, long long>p2) {
	return p1.second < p2.second;
}

int bsearch(vector<long long>* temp, long long t) {
	int beg = 0;
	int fin = temp->size();
	int mid;
	while (beg <= fin) {
		mid = (beg + fin) / 2;
		if ((*temp)[mid] <= t)
			beg = mid + 1;
		else
			fin = mid - 1;
	}
	if (fin == -1)
	{
		return 0;
	}
	else
	{
		mid = (beg + fin) / 2;
		if ((*temp)[mid] <= t)
			return mid + 1;
		else
			return mid;
	}
}
long long findLIS() {
	vector<long long> temp;
	int num = 0;
	temp.push_back(points[0].second);
	num++;
	for (int i = 1; i < N; i++) {
		if (points[i].second >= temp[num - 1]) {
			temp.push_back(points[i].second);
			num++;
		}
		else {
			temp[bsearch(&temp, points[i].second)] = points[i].second;
		}
	}
	return num++;
}

int main() {
	cin >> temp1;
	long long y_now;
	long long ylabel;
	for (int i = 0; i < temp1; i++)
	{
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> x >> y;
			points.push_back(make_pair(x, y));
		}
		stable_sort(points.begin(), points.end(), comparey);
		stable_sort(points.begin(), points.end());
		ans[i] = findLIS();
		points.clear();
	}
	for (int i = 0; i < temp1; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}