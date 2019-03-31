#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct Vertice {
	int f;
	long long price;
	long long distance;
	Vertice(int _f, long long _price, long long _distance) {
		f = _f;
		price = _price;
		distance = _distance;
	}
};
struct Node {
	int myindex;
	long long distFromStart = -1;
	int prev = -1;
	Node(int _myindex = 0, int _distFromStart = -1, int _prev = -1) {
		myindex = _myindex;
		distFromStart = _distFromStart;
		prev = _prev;
	}
};
class Compare {
public:
	bool operator()(const Node& a, const Node& b) {
		if (a.distFromStart == b.distFromStart)
			return false;
		if (a.distFromStart == -1)
			return true;
		else if (b.distFromStart == -1)
			return false;
		else
			return (a.distFromStart >= b.distFromStart);
	}
};
bool mycompare(long long a, long long b) {
	if (a == -1)
		return true;
	else if (b == -1)
		return false;
	else
		return a > b;
}
long long myplus(long long a, long long b) {
	if (a == -1 || b == -1)
		return -1;
	else
		return a + b;
}

vector<Vertice> graph[1000];
vector<int> route[100];
long long priceList[100002];
int temp1;
int P, S;
long long M;
int u, v;
long long p, d;
long long ans[100];
int i;
priority_queue<Node, vector<Node>, Compare> pqueueForDijkstra;
bool Dijkstra(int start, long long p, long long limitdis, bool drawroute) {
	Node node[1000];
	int distanceFromS[1000];
	fill_n(distanceFromS, P, -1);
	distanceFromS[0] = 0;
	node[0].distFromStart = 0;
	for (int i = 0; i < P; i++) {
		node[i].myindex = i;
		pqueueForDijkstra.push(node[i]);
	}
	Node temp;
	while (pqueueForDijkstra.size() > 0) {
		temp = pqueueForDijkstra.top();
		pqueueForDijkstra.pop();
		if (mycompare(temp.distFromStart, distanceFromS[temp.myindex]))
			continue;
		for (int i = 0; i < graph[temp.myindex].size(); i++) {
			if (graph[temp.myindex][i].price > p || node[graph[temp.myindex][i].f].distFromStart == myplus(temp.distFromStart, graph[temp.myindex][i].distance))
				continue;
			if (mycompare(node[graph[temp.myindex][i].f].distFromStart, myplus(temp.distFromStart, graph[temp.myindex][i].distance)))
			{
				node[graph[temp.myindex][i].f].distFromStart = myplus(temp.distFromStart, graph[temp.myindex][i].distance);
				distanceFromS[graph[temp.myindex][i].f] = myplus(temp.distFromStart, graph[temp.myindex][i].distance);
				node[graph[temp.myindex][i].f].prev = temp.myindex;
				pqueueForDijkstra.push(node[graph[temp.myindex][i].f]);
			}
		}
	}
	if (mycompare(distanceFromS[P - 1], limitdis))
		return false;
	
	if (drawroute == true)
	{
		temp = node[P - 1];
		while (temp.prev != -1)
		{
			route[i].push_back(temp.myindex);
			temp = node[temp.prev];
		}
		route[i].push_back(0);
	}

	return true;
}
int main() {
	cin >> temp1;
	for (i = 0; i < temp1; i++) {
		cin >> P >> S >> M;
		for (int j = 0; j < S; j++) {
			cin >> u >> v >> p >> d;
			graph[u].push_back(Vertice(v, p, d));
			priceList[j] = p;
		}
		priceList[S] = 2147483650;
		sort(priceList, priceList + S+1);
		
		int beg = 0;
		int fin = S;

		while (beg < fin) {
			if (Dijkstra(0, priceList[(beg + fin) / 2], M, false))
				fin = (beg + fin) / 2 ;
			else
				beg = (beg + fin) / 2 + 1;
		}

		ans[i] = priceList[(beg + fin) / 2]; //À½...
		Dijkstra(0, priceList[(beg + fin) / 2], M, true);

		for (int j = 0; j < P; j++) {
			graph[j].clear();
		}
		for (int j = 0; j < S+1; j++) {
			priceList[j] = 0;
		}
	}
	for (i = 0; i < temp1; i++)
	{
		if (ans[i] == 2147483650)
			cout << -1 << endl;
		else
		{
			cout << ans[i] << endl;
		}
	}
//	system("PAUSE");
	return 0;
}