/*#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
long long temp1;
long long temp2[100];
long long ans[100];
long long u, v, p, d;
long long P, S, M;
long long shortestPath[1000];
long long Pmax;
struct myData {
	long long v;
	long long p;
	long long d;
	myData(long long _v, long long _p, long long _d)
	{
		v = _v;
		p = _p;
		d = _d;
	}
};
vector<myData> graph[1000];
bool dijstra(long long plimit) {
	for (int i = 0; i < P; i++)
		shortestPath[i] = 2147483649ll;
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> myHeap;
	myHeap.push(make_pair(0, 0));
	shortestPath[0] = 0;
	for (long long i = 1; i < P; i++)
		myHeap.push(make_pair(2147483649ll, i));
	while (!myHeap.empty()) {
		pair<long long, long long> temp = myHeap.top();
		myHeap.pop();
		if (temp.first > shortestPath[temp.second])
			continue;

		for (int i = 0; i < graph[temp.second].size(); i++) {
			if (graph[temp.second][i].p > plimit)
				continue;
			if (shortestPath[graph[temp.second][i].v] > shortestPath[temp.second] + graph[temp.second][i].d)
			{
				shortestPath[graph[temp.second][i].v] = shortestPath[temp.second] + graph[temp.second][i].d;
				myHeap.push(make_pair(shortestPath[graph[temp.second][i].v], graph[temp.second][i].v));
			}
		}
	}
	if (shortestPath[P - 1] <= M)
		return true;
	else
		return false;
}
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		cin >> P >> S >> M;
		Pmax = 0;
		for (int j = 0; j < S; j++) {
			cin >> u >> v >> p >> d;
			if (p > Pmax)
				Pmax = p;
			graph[u].push_back(myData(v, p, d));
		}
		long long beg = 0;
		long long end = Pmax+1;
		long long mid;
		while (end >= beg) {
			mid = (beg + end) / 2;
			if (dijstra(mid))
				end = mid - 1;
			else
				beg = mid + 1;
		}

		if (beg > Pmax)
			ans[i] = -1;
		else if (dijstra((beg + end) / 2))
			ans[i] = (beg + end) / 2;
		else
			ans[i] = (beg + end) / 2 + 1;
		for (int j = 0; j < P; j++)
			graph[j].clear();
	}
	for (int i = 0; i < temp1; i++) {
		cout << ans[i] << endl;
	}
//	system("PAUSE");
	return 0;

}
*/