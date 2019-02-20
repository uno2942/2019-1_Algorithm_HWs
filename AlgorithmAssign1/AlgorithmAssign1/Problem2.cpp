#include<iostream>

using namespace std;

long long mydata[100][1000000];
long long len[100];
long long ans[100];
int CalcDistance(const long long* data1, int len, int index) {
	int tot = 0;
	int tmp = 0;
	for (int i = 0; i < len; i++) {
		tmp = data1[i] - data1[index];
		if (tmp > 0)
			tot += tmp;
		else
			tot -= tmp;
	}
	return tot;
}

int main() {
	int num1;
	cin >> num1;
	for (int i = 0; i < num1; i++)
	{
		cin >> len[i];
		for (int j = 0; j < len[i]; j++)
			cin >> mydata[i][j];
	}
	for (int i = 0; i < num1; i++)
	{
		int bestplaceindex = len[i]/2;
		int tot1 = CalcDistance(mydata[i], len[i], bestplaceindex);
		int tot2 = tot1;
		int leftmost, rightmost, temp;
		for (leftmost = bestplaceindex; leftmost >= 0; leftmost--)
		{
			temp = CalcDistance(mydata[i], len[i], leftmost);
			if (tot1 <= temp)
				break;
			tot1 = temp;
		}
		for (rightmost = bestplaceindex; rightmost < len[i]; rightmost++)
		{
			temp = CalcDistance(mydata[i], len[i], rightmost);
			if (tot2 <= temp)
				break;
			tot2 = temp;
		}
		if(tot2>=tot1)
			ans[i] = CalcDistance(mydata[i], len[i], leftmost);
		else
			ans[i] = CalcDistance(mydata[i], len[i], rightmost);
	}
	for (int i = 0; i < num1; i++)
		cout << ans[i] << endl;
	return 0;
}
