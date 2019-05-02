/*#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long myarray[3000][3000];
long long mytemphorizon[3000];
long long mytempvertical[3000][3000];
long long N[101];
long long M[101];
long long d[101];
int temp1;
vector<int> ansarr[100][3000];
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		cin >> N[i] >> M[i] >> d[i];
		for (int j = 0; j < N[i]; j++) {
			for (int k = 0; k < M[i]; k++) {
				cin >> myarray[j][k];
			}
		}

		for (int j = 0; j < N[i]; j++)
		{
			mytemphorizon[j] = 0;
			for (int k = 0; k < d[i]; k++)
				mytemphorizon[j] += myarray[j][k];
		}

		for (int k = 0; k < M[i]; k++)
		{
			mytempvertical[0][k] = 0;
			for (int j = 0; j < d[i]; j++)
				mytempvertical[0][k] += myarray[j][k];
			for (int j = 1; j <= N[i] - d[i]; j++) {
				mytempvertical[j][k] = mytempvertical[j - 1][k] - myarray[j - 1][k] + myarray[(j - 1) + d[i]][k];
			}
		}

		ansarr[i][0].push_back(0);
		for (int j = 0; j < d[i]; j++) {
			for (int k = 0; k < d[i]; k++)
				ansarr[i][0][0] += myarray[j][k];
		}
		for (int k = 1; k <= M[i] - d[i]; k++) {
			ansarr[i][0].push_back(ansarr[i][0][k - 1] - mytempvertical[0][k - 1] + mytempvertical[0][k - 1 + d[i]]);
			//ansarr[i][0][k] = ansarr[i][0][k - 1] - mytempvertical[0][k - 1] + mytempvertical[0][k - 1 + d[i]];
		}
		for (int j = 1; j <= N[i] - d[i]; j++) {
			ansarr[i][j].push_back(ansarr[i][j - 1][0] - mytemphorizon[j - 1] + mytemphorizon[j - 1 + d[i]]);
			//ansarr[i][j][0] = ansarr[i][j - 1][0] - mytemphorizon[j - 1] + mytemphorizon[j - 1 + d[i]];

			for (int k = 1; k <= M[i] - d[i]; k++) {
				ansarr[i][j].push_back(ansarr[i][j][k - 1] - mytempvertical[j][k - 1] + mytempvertical[j][k - 1 + d[i]]);
				//ansarr[i][j][k] = ansarr[i][j][k - 1] - mytempvertical[j][k - 1] + mytempvertical[j][k - 1 + d[i]];
			}
		}
	}
	for (int i = 0; i < temp1; i++) {
		for (int j = 0; j <= N[i] - d[i]; j++) {
			for (int k = 0; k <= M[i] - d[i]; k++) {
				cout << ansarr[i][j][k] << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}
*/