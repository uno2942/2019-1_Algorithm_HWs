#include<iostream>
#include<algorithm>

using namespace std;
struct Vertice {
	short initial;
	short final[3000];
	int weight[3000];
	short numOfFinal = 0;
	long long int myweight;
	bool isChecked = false;
};
int temp1;
int temp2[30];
int V, E;
Vertice Vertices[30][3000];
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		int a, b, w;
		cin >> temp2[i];
		cin >> V >> E;
		for (int j = 0; j < temp2[i]; j++) {
			cin >> a >> b >> w;
			Vertices[i][a].initial = a;
			Vertices[i][a].final[Vertices[i][a].numOfFinal] = b;
			Vertices[i][a].numOfFinal++;
			Vertices[i][a].weight[Vertices[i][a].numOfFinal] = w;
		}
	}
}