/*
#include<iostream>
#include<vector>

using namespace std;

struct node {
	int f;
	int w;
	node(int _f, int _w) : f(_f), w(_w) {

	}
};
vector<node> graph[3000];
bool isChecked[3000];
int c;
int thres;
int numofcheckednode;
int temp1;
int V, E;
long long u,v,w;
long long w_max;
long long ans[100];
void dfs(int myindex) {
	isChecked[myindex] = true;
	numofcheckednode++;
	for (int i = 0; i < graph[myindex].size(); i++) {
		if (!isChecked[graph[myindex][i].f]) {
			if (graph[myindex][i].w >= thres)
				dfs(graph[myindex][i].f);
		}
	}
}
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {

		cin >> V >> E;
		for (int j = 0; j < E; j++) {
			cin >> u >> v >> w;
			if (w_max < w)
				w_max = w;
			graph[u].push_back(node(v, w));
			graph[v].push_back(node(u, w));
		}
		int beg = 0;
		int end = w_max;
		while (beg <= end) {
			thres = (beg + end) / 2;
			numofcheckednode = 0;
			for (int j = 0; j < V; j++)
			{
				isChecked[j] = false;
			}
			dfs(0);
			if (numofcheckednode != V)
				end = thres - 1;
			else
				beg = thres + 1;
		}
		numofcheckednode = 0;
		for (int j = 0; j < V; j++)
		{
			isChecked[j] = false;
		}
		dfs(0);
		if (numofcheckednode == V)
			ans[i] = thres;
		else
			ans[i] = thres - 1;
		for (int j = 0; j < V; j++)
		{
			isChecked[j] = false;
			graph[j].clear();
			numofcheckednode = 0;
		}
	}
	for (int i = 0; i < temp1; i++)
		cout << ans[i] << endl;
	return 0;
}
*/