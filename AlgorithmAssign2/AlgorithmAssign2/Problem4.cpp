/*#include<iostream>
#include<algorithm>
#include<fstream>
#include<ctime>
using namespace std;
unsigned int A[5001];
unsigned int B[200001];
unsigned int ans[10000];
int temp1;
int temp2[50];
long long n, m, k;
long long amin;
long long amax;
bool overkFlag = false;

long long MyBinarySearchx_rec(long long target, int y, int begin, int end)
{
	if (end - begin == 1)
	{
		if (A[y] * B[begin] <= target)
			return begin + 1;
		else
			return begin;
	}
	if (target < A[y] * B[(begin + end) / 2])
		return MyBinarySearchx_rec(target, y, begin, (begin + end) / 2);
	else
		return MyBinarySearchx_rec(target, y, (begin + end) / 2, end);
}

long long CalcNum(long long target, int width, int height) {
	long long temp = 0;
	for (int i = 0; i < n; i++)
		temp+=(MyBinarySearchx_rec(target, i, 0, m));
	return temp;
}
long long Finda(long long begin, long long candidate, long long end) {
	if (end - begin <= 1) {
		if (CalcNum(begin, m, n) == k)
			return begin;
		else
			return begin+1;
	}
	long long num1 = CalcNum(candidate, m, n);
	if (num1 >= k)
		return Finda(begin, (begin + candidate) / 2, candidate);
	else
		return Finda(candidate, (end + candidate) / 2, end);
}
int main() {
//	string filePath = "test.txt";
//	ifstream openFile(filePath.data());
//	openFile >> temp1;
	cin >> temp1;

//	clock_t start = clock();
	for (int i = 0; i < temp1; i++) {
		//		openFile >> n >> m >> k;
		cin >> n >> m >> k;
		for (int j = 0; j < n; j++) {
			//			openFile >> A[j];
			cin >> A[j];
		}
		for (int j = 0; j < m; j++) {
			//			openFile >> B[j];
			cin >> B[j];
		}
		sort(A, A + n);
		sort(B, B + m);
		long long maxofcandidate = A[0] * B[0];
		long long minofcandidate = A[n - 1] * B[m - 1];
		long long a = (A[0] * B[0] + A[n-1]*B[m-1]) / 2;
		ans[i] = Finda(minofcandidate, a, maxofcandidate);
	}
	for (int i = 0; i < temp1; i++)
		cout << ans[i] << endl;
//	cout << (double)(clock()-start) / CLOCKS_PER_SEC<<endl;
	system("PAUSE");
	return 0;
}
*/