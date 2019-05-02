/*#include<iostream>
#include<algorithm>
using namespace std;

long long myArray[3001][3001];
long long ans[3001][3001];
long long finans[200];
long long from_left_to_right_ans[3001];
long long from_right_to_left_ans[3001];
int temp1;
int N, M;
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		{
			cin >> N >> M;
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++)
					cin >> myArray[j][k];
			}
		}

		ans[0][0] = myArray[0][0];
		
		for (int k=1; k<M; k++)
			ans[0][k] = ans[0][k - 1] + myArray[0][k];
	
		for (int j = 1; j < N; j++) {
			from_left_to_right_ans[0] = ans[j - 1][0] + myArray[j][0];
			from_right_to_left_ans[M-1] = ans[j - 1][M-1] + myArray[j][M-1];
			for (int k = 1; k < M; k++)
			{
				from_left_to_right_ans[k] = max(from_left_to_right_ans[k - 1] + myArray[j][k], ans[j - 1][k] + myArray[j][k]);
				from_right_to_left_ans[M-1-k] = max(from_right_to_left_ans[M-1-k + 1] + myArray[j][M - 1 - k], ans[j - 1][M - 1 - k] + myArray[j][M - 1 - k]);
			}
			for (int k = 0; k < M; k++) {
				ans[j][k] = max(from_left_to_right_ans[k], from_right_to_left_ans[k]);
			}
		}
		finans[i] = ans[N - 1][M - 1];
	}

	for (int i = 0; i < temp1; i++) {
		cout << finans[i]<<endl;
	}
	return 0;
}
*/