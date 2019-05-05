#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int temp1;
int N;
int x, y;
vector<pair<int, int>> points;
vector<int> graph[1001];
int weight[1001];
int nums[1001];
int ans[101];
int dfs(int p, int depth) {
	
}
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		cin >> N;
		points.push_back(make_pair(0, 0));
		for (int j = 0; j < N; j++) {
			cin >> x >> y;
			points.push_back(make_pair(x, y));
		}

		for (int j = 0; j < N + 1; j++) {
			for (int k = 0; k < N + 1; k++) {
				if (points[k].first <= points[j].first && points[k].second <= points[j].second && j!=k)
					graph[k].push_back(j);
			}
		}
		ans[i]=dfs(0, 0);
		for (int j = 0; j < N; j++) {
			nums[j] = 0;
			graph[i].clear();
		}
		points.clear();
	}
}