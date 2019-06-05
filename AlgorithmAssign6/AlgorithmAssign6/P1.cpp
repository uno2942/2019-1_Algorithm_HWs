/*#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int cap[505][505];
vector<int> graph[505];
int prevs[505];
int reachable[505];
vector<int> reachablevector;
bool isInserted[505][505];
long long temp1;
int n, m;
int u, v, c;
long long ans[200];
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		cin >> n >> m;
		for (int j = 0; j < n + 2; j++) {
			for (int k = 0; k < n + 2; k++)
				isInserted[j][k] = false;
		}
		for (int j = 0; j < m; j++) {
			cin >> u >> v >> c;
			u++;
			v++;
			if (!isInserted[u][v])
			{
				graph[u].push_back(v);
				graph[v].push_back(u);
				cap[u][v] = c;
				isInserted[u][v] = true;
				isInserted[v][u] = true;
			}
			else
				cap[u][v] = c;
		}
		graph[0].push_back(1);
		graph[1].push_back(0);
		cap[0][1] = 20000;
		cap[1][0] = 0;
		graph[n + 1].push_back(n);
		graph[n].push_back(n + 1);
		cap[n][n + 1] = 20000;
		cap[n + 1][n] = 0;

		while (true) {
			queue<int> qdfs;
			qdfs.push(0);
			for (int j = 0; j < n + 2; j++) {
				prevs[j] = -1;
			}
			prevs[0] = -2;
			while (!qdfs.empty()) {
				int from = qdfs.front();
				qdfs.pop();
				for (int j = 0; j < graph[from].size(); j++) {
					int to = graph[from][j];
					if (to == n + 1 && cap[from][to] > 0)
					{
						prevs[n + 1] = from;//it is shortest path
						break;
					}
					if (prevs[graph[from][j]] == -1 && cap[from][to] > 0) {
						prevs[graph[from][j]] = from;
						qdfs.push(graph[from][j]);
					}
				}
				if (prevs[n + 1] != -1)
					break;
			}

			if (prevs[n + 1] == -1)
			{*/
				//make answer
				/*reachablevector.clear();
				for (int j = 0; j < n; j++)
					reachable[j] = 0;
				queue<int> qdfs;
				reachablevector.push_back(0);
				qdfs.push(0);
				while (!qdfs.empty()) {
					int from = qdfs.front();
					qdfs.pop();
					for (int j = 0; j < graph[from].size(); j++) {
						int to = graph[from][j];
						if (reachable[graph[from][j]] == 0 && cap[from][to] > 0) {
							reachable[graph[from][j]] = 1;
							reachablevector.push_back(graph[from][j]);
							qdfs.push(graph[from][j]);
						}
					}
				}

				tempans = 0;
				for (int j = 0; j < reachablevector.size(); j++) {
					for (int k = 0; k < graph[reachablevector[j]].size(); k++)
					{
						if (reachable[reachablevector[j]] == 1 && reachable[graph[reachablevector[j]][k]] == 0)
							tempans += cap[graph[reachablevector[j]][k]][reachablevector[j]];
					}
				}
				*/
/*
				ans[i] = cap[1][0];
				for (int j = 0; j < n + 2; j++)
				{
					graph[j].clear();
					for (int k = 0; k < n + 2; k++) {
						cap[j][k] = 0;
					}
				}

				break;
			}
			else
			{
				int extraflow = 20000;
				int j = n + 1;
				while (prevs[j] >= 0) {
					extraflow = min(extraflow, cap[prevs[j]][j]);
					j = prevs[j];
				}
				j = n + 1;
				while (prevs[j] >= 0) {
					cap[prevs[j]][j] -= extraflow;
					cap[j][prevs[j]] += extraflow;
					j = prevs[j];
				}
			}
		}
	}
	for (int i = 0; i < temp1; i++)
	{
		cout << ans[i] << endl;
	}
}*/