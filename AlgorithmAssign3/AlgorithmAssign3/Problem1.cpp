#include<iostream>
#include<algorithm>

using namespace std;
struct Vertice {
	int initialNode;
	int finalNode;
	int myweight;
	Vertice* next;
	Vertice(int i, int f, int w) {
		initialNode = i;
		finalNode = f;
		myweight = w;
		next = NULL;
	}
};
int temp1;
int V, E;
long long int totalweight[3000];
Vertice* vertices[3000];
Vertice* finalVertices[3000];
bool isChecked[3000];
int ans[100];
int findweight(Vertice* root) {
	if (root == NULL)
	{
		isChecked[root->initialNode] == true;
		return 0;
	}
	if (isChecked[root->initialNode] == true)
		return totalweight[root->initialNode];

	long long a1 = findweight(vertices[root->finalNode]) + root->myweight; 
	long long a2;
	Vertice* temp = root->next;
	while (temp != NULL)
	{
		a2 = findweight(vertices[temp->finalNode]) + temp->myweight;
		if (a1 < a2)
			a1 = a2;
		temp = temp->next;
	}
	isChecked[root->initialNode] = true;
	totalweight[root->initialNode] = a1;
	return a1;
}
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		int a, b, w;
		cin >> V >> E;
		for (int j = 0; j < E; j++) {
			cin >> a >> b >> w;
			if (vertices[a] == NULL)
			{
				vertices[a] = new Vertice(a, b, w);
				finalVertices[a] = vertices[a];
				continue;
			}
			finalVertices[a]->next = new Vertice(a, b, w);
			finalVertices[a] = finalVertices[a]->next;
		}
		a = -1;
		
		for (int j = 0; j < V; j++) {
			b=findweight(vertices[j]);
			if (b > a)
				a = b;
		}
		ans[i] = a;

		for (int j = 0; j < V; j++)
		{
			Vertice* temp = vertices[j];
			Vertice* temp2;
			while (temp != NULL)
			{
				temp2 = temp->next;
				delete temp;
				temp = temp2;
			}
		}
		for (int j = 0; j < 3000; j++)
		{
			totalweight[j] = 0;
			vertices[j] = NULL;
			finalVertices[j] = NULL;
			isChecked[j] = 0;
		}
	}
	for (int i = 0; i < temp1; i++)
		cout << ans[i] << endl;
	return 0;
}