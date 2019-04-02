/*#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> myData[100001];
int temp1;
int temp2[100];
int f, d;
int d_max;
int c;
long long ans[100];
struct compare {
	bool operator()(int a, int b) { return a > b; }
};
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		d_max = 0;
		priority_queue<int> pq;
		cin >> temp2[i];
		for (int j = 0; j < temp2[i]; j++) {
			cin >> f >> d;
			if (d_max < d)
				d_max = d;
			myData[d-1].push_back(f);
		}
		for (int j = 0; j < d_max; j++) {
			for (int k = 0; k < myData[d_max - 1 - j].size(); k++)
				pq.push(myData[d_max - 1 - j][k]);
			if (pq.size())
			{
				ans[i] += pq.top();
				pq.pop();
			}
		}
		for (int j = 0; j < d_max; j++)
			myData[j].clear();
	}
	for (int i = 0; i < temp1; i++)
		cout << ans[i] << endl;
	return 0;
}
*/