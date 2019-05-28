#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int temp1;
long long ans[500];
long long graph[12][12];
vector<int> adj[12];
int u, v;
long long c;
int n_max, e;
long long path_min;
bool checked[12];
void find_min(int start, int n, long long min_temp) {
	if (n == n_max - 1)
	{
		if(graph[start][0]!=-1)
			path_min = min(path_min, min_temp + graph[start][0]);
		return;
	}
	n++;
	for (int i = 0; i < adj[start].size(); i++) {
		if (!checked[adj[start][i]]) {
			checked[adj[start][i]] = true;
			find_min(adj[start][i], n, min_temp + graph[start][adj[start][i]]);
			checked[adj[start][i]] = false;
		}
	}
}
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		cin >> n_max >> e;
		path_min = 200000;
		for (int j = 0; j < 12; j++)
		{
			for (int k = 0; k < 12; k++) {
				graph[j][k] = -1;
			}
		}
		for (int j = 0; j < e; j++) {
			cin >> u >> v >> c;
			if (graph[u][v] == -1)
			{
				graph[u][v] = c;
				graph[v][u] = c;
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
			else
			{
				graph[u][v] = min(c, graph[u][v]);
				graph[v][u] = graph[u][v];
			}
		}
		for (int j = 0; j < 12; j++)
			checked[j] = false;
		checked[0] = true;
		find_min(0, 0, 0);
		if (path_min == 200000)
			ans[i] = -1;
		else
			ans[i] = path_min;
		for (int j = 0; j < n_max; j++) {
			adj[j].clear();
		}
	}
	for (int i = 0; i < temp1; i++) {
		cout << ans[i] << endl;
	}
}