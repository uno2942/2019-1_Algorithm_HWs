/*#include<iostream>
#include<algorithm>
using namespace std;
unsigned int A[5000];
unsigned int B[200000];
unsigned int ans[50];
int temp1;
int temp2[50];
long long n, m, k;
long long amin;
long long amax;
long long MyBinarySearchy_rec(long long target, int x, int begin, int end) {
	if (end - begin <= 0)
		return 0;
	else if (end - begin == 1)
	{
		if (A[begin] * B[x] <= target)
			return 1;
		return 0;
	}
	else if (A[(begin + end) / 2] * B[x] > target) {
		if (A[(begin + end) / 2 -1] * B[x] <= target)
			return (end - begin) / 2;
		else
			MyBinarySearchy_rec(target, x, begin, (begin + end) / 2);
	}
	else 
		return ((end - begin) / 2 + 1) + MyBinarySearchy_rec(target, x, (begin + end) / 2 + 1, end);
}

long long MyBinarySearchx_rec(long long target, int y, int begin, int end) {
	if (end - begin <= 0)
		return 0;
	else if (end - begin == 1)
	{
		if (A[y] * B[begin] <= target)
			return 1;
		return 0;
	}
	else if (A[y] * B[(begin + end) / 2] > target) {
		if (A[y] * B[(begin + end) / 2 - 1] <= target)
			return (end - begin) / 2;
		else
			MyBinarySearchx_rec(target, y, begin, (begin + end) / 2);
	}
	else 
		return ((end - begin) / 2 + 1) + MyBinarySearchx_rec(target, y, (begin + end) / 2 + 1, end);
}

long long CalcNum_rec(long long target, int xbegin, int xend, int ybegin, int yend) {
	if (yend - ybegin == 0 || xend - xbegin == 0)
		return 0;
	else {
		if (yend - ybegin == 1) {
			return MyBinarySearchx_rec(target, ybegin, xbegin, xend);
		}
		else if (xend - xbegin == 1)
		{
			return MyBinarySearchy_rec(target, xbegin, ybegin, yend);
		}
		else
		{
			int xmid = (xbegin + xend) / 2;
			int ymid = (ybegin + yend) / 2;
			if (B[xmid] * A[ymid] > target)
				return CalcNum_rec(target, xbegin, xmid, ybegin, ymid)
				+ CalcNum_rec(target, xmid, xend, ybegin, ymid)
				+ CalcNum_rec(target, xbegin, xmid, ymid, yend);
			else
				return CalcNum_rec(target, xmid + 1, xend, ymid + 1, yend)
				+ CalcNum_rec(target, xmid + 1, xend, ybegin, ymid + 1)
				+ CalcNum_rec(target, xbegin, xmid + 1, ymid + 1, yend)
				+ (xmid + 1)*(ymid + 1);
		}
	}
}
long long CalcNum(long long target, int width, int height) {
	return CalcNum_rec(target, 0, width, 0, height);
}

long long Finda(long long begin, long long candidate, long long end) {
	long long num1 = CalcNum(candidate, m, n);
	if (num1 >= k && CalcNum(candidate - 1, m, n) < k)
		return candidate;
	else {
		if (num1 > k)
			Finda(begin, (candidate + begin) / 2, candidate);
		else
			Finda(candidate, (candidate + end) / 2, end);
	}
}
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		cin >> n >> m >> k;
		for (int j = 0; j < n; j++) {
			cin >> A[j];
		}
		for (int j = 0; j < m; j++) {
			cin >> B[j];
		}
		sort(A, A + n);
		sort(B, B + m);
		int nmax = sqrt(k/4);
		amax = A[nmax] * (long long)B[nmax];
		int nmin = ((2 * n + m / 2) - sqrt((2 * n + m / 2)*(2 * n + m / 2) - 4 * k)) / 4;
		amin = A[nmin] * (long long)B[nmin];
		long long a = A[n / 2] * B[m / 2];
		ans[i] = Finda(A[0] * B[0], a, A[n - 1] * B[m - 1]);
	}
	for (int i = 0; i < temp1; i++)
		cout << ans[i] << endl;
//	system("PAUSE");
	return 0;
}
*/