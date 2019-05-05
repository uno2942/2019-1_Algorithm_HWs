/*#include<iostream>
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
bool isChecked[1001];
int ans[101];
int mydepth[1001];
void dfs(int p, int depth) {
	depth++;
	mydepth[p] = depth;
	for (int i = 0; i < graph[p].size(); i++) {
		if ((depth+1)>mydepth[graph[p][i]]) {
				dfs(graph[p][i], depth);
		}
	}
}
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		bool isZero = false;
		cin >> N;
		points.push_back(make_pair(0, 0));
		for (int j = 0; j < N; j++) {
			cin >> x >> y;
			if (x == 0 && y == 0) {
				isZero = true;
				continue;
			}
			points.push_back(make_pair(x, y));
		}
		if (!isZero)
			N++;
		for (int j = 0; j < N ; j++) {
			for (int k = 0; k < N ; k++) {
				if (points[k].first <= points[j].first && points[k].second <= points[j].second && j!=k)
					graph[k].push_back(j);
			}
		}
		dfs(0, 0);
		ans[i] = mydepth[0];
		for (int j = 1; j < N; j++) {
			if (ans[i] < mydepth[j])
				ans[i] = mydepth[j];
		}
		if (!isZero)
			ans[i]--;
		for (int j = 0; j < N ; j++) {
			mydepth[j] = 0;
			graph[j].clear();
		}
		points.clear();
	}
	for (int i = 0; i < temp1; i++) {
		cout << ans[i] << endl;
	}
}

*/