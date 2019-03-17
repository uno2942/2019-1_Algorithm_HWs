/*#include<iostream>
#include<algorithm>
using namespace std;
long long A[5000];
long long B[200000];
long long ans[200];
long long temp1;
long long n, m, k;

long long MyBinarySearchx(long long target, long long y)
{
	long long begin = 0;
	long long end = m-1;
	long long candidate;
	while (begin <= end) {
		long long mid = (begin + end) / 2;
		candidate = A[y]*B[mid];
		if (target < candidate)
			end = mid - 1;
		else
			begin = mid + 1;
	}
	return (begin + end + 1) / 2;
}

long long CalcNum(long long target) {
	long long temp = 0;
	for (long long i = 0; i < n; i++)
		temp += (MyBinarySearchx(target, i));
	return temp;
}



long long Finda(long long begin, long long end) {
	while (begin <= end) {
		long long candidate = (begin + end) / 2;
		long long t = CalcNum(candidate);
		if (t >= k)
			end = candidate - 1;
		else
			begin = candidate + 1;
	}
	return (begin + end + 1) / 2;
}

int main() {
	cin >> temp1;

	for (long long i = 0; i < temp1; i++) {
		cin >> n >> m >> k;
		for (long long j = 0; j < n; j++) {
			cin >> A[j];
		}
		for (long long j = 0; j < m; j++) {
			cin >> B[j];
		}
		sort(A, A + n);
		sort(B, B + m);
		long long minofcandidate = A[0] * B[0];
		long long maxofcandidate = A[n - 1] * B[m - 1];
		ans[i] = Finda(minofcandidate, maxofcandidate);
	}
	for (long long i = 0; i < temp1; i++)
		cout << ans[i] << endl;
//	system("PAUSE");
	return 0;
}
*/