/*#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int temp1;
int N;
long long x, y;
long long tempans[310][310];
vector<pair<long long, long long>> points;
long long ans[110];
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		bool isZero = false;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> x >> y;
			points.push_back(make_pair(x, y));
		}
	
	points.insert(points.begin(), make_pair(0, 0));
	N++;
	tempans[N - 1][N - 1] = 0;
	for (int i = 0; i < N - 1; i++) {
		tempans[i][N - 1] = abs(points[i].second - points[N - 1].second);
		tempans[N - 1][i] = tempans[i][N - 1];
	}
	for (int j = N - 2; j >= 0; j--) {
		for (int k = j - 1; k >= 0; k--)
		{
			long long front = max(j, k) + 1;
			tempans[j][k] = min(tempans[front][k] + abs(points[j].second - points[front].second),
				tempans[j][front] + abs(points[k].second - points[front].second));
			tempans[k][j] = tempans[j][k];
		}
	}
	ans[i] = tempans[0][1] + abs(points[1].second) + 2*points[N-1].first;
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			tempans[j][k] = 0;
		}
	}
	points.clear();
	}
	for (int i = 0; i < temp1; i++)
	{
		cout << ans[i]<<endl;
	}
	return 0;
}
*/