#include<iostream>
#include<algorithm>
#include<fstream>
#include<ctime>
using namespace std;
unsigned int A[5000];
unsigned int B[200000];
unsigned int ans[10000];
int temp1;
int temp2[50];
long long n, m, k;
long long amin;
long long amax;
bool overkFlag = false;
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
			return MyBinarySearchy_rec(target, x, begin, (begin + end) / 2);
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
			return MyBinarySearchx_rec(target, y, begin, (begin + end) / 2);
	}
	else 
		return ((end - begin) / 2 + 1) + MyBinarySearchx_rec(target, y, (begin + end) / 2 + 1, end);
}

long long CalcNum_rec(long long target, int xbegin, int xend, int ybegin, int yend) {
	if (overkFlag == true) return 0;
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
			{
				long long t = CalcNum_rec(target, xbegin, xmid, ybegin, ymid)
					+ CalcNum_rec(target, xmid, xend, ybegin, ymid)
					+ CalcNum_rec(target, xbegin, xmid, ymid, yend);
				if (t > k) {
					overkFlag = true; return (k+1);
				}
				else 
					return t;
			}
			else {
				long long t = CalcNum_rec(target, xmid + 1, xend, ymid + 1, yend)
					+ CalcNum_rec(target, xmid + 1, xend, ybegin, ymid + 1)
					+ CalcNum_rec(target, xbegin, xmid + 1, ymid + 1, yend)
					+ (xmid + 1)*(ymid + 1);
				if (t > k) {
					overkFlag = true; return (k+1);
				}
				else
					return t;
			}
				
		}
	}
}
long long CalcNum(long long target, int width, int height) {
	long long t = CalcNum_rec(target, 0, width, 0, height);
	if (overkFlag == true)
	{
		overkFlag = false;
		return k + 1;
	}
	else
		return t;
}

int MyBinarySearchxForB_rec(long long target, int begin, int end) {
	if (end - begin <= 0)
		return -1;
	else if (end - begin == 1)
	{
		if (B[begin] == target)
			return begin;
		return -1;
	}
	else if (B[(begin + end) / 2] == target) {
		return (begin + end) / 2;
	}
	else {
		int b1 = MyBinarySearchxForB_rec(target, (begin + end) / 2 + 1, end);
		if (b1 != -1)
			return b1;
		int b2 = MyBinarySearchxForB_rec(target, begin, (begin + end) / 2);
		if (b2 != -1)
			return b2;
		return -1;
	}
}

long long DecreaseOne(long long candidate, int xbegin, int xend, int ybegin, int yend) {
	int count = 0;
	for (int i = ybegin; i < yend; i++) {
		if (A[i] == 0) continue;
		if (candidate % A[i] == 0) {
			long long term = candidate / A[i];
			int pos = (MyBinarySearchxForB_rec(term, xbegin, xend));
			if (pos == -1)
				continue;
			for (int j = pos; j >= ybegin; j--)
			{
				if (B[j] == term)
				{
					count++;
				}
				else
					break;
			}
			for (int j = pos + 1; j < yend; j++)
			{
				if (B[j] == term)
				{
					count++;
				}
				else
					break;
			}
		}
	}
	return count;
}

long long Finda(long long begin, long long candidate, long long end) {
	long long num1 = CalcNum(candidate, m, n);
	
	if (num1 >= k && num1-DecreaseOne(candidate, 0, m, 0, n) < k)
		return candidate;
	else {
		if (num1 >= k)
			Finda(begin, (candidate + begin) / 2, candidate);
		else
			Finda(candidate, (candidate + end) / 2, end);
	}
}


int main() {
//	string filePath = "test.txt";
//	ifstream openFile(filePath.data());
//	openFile >> temp1;
	cin >> temp1;

	clock_t start = clock();
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
		long long maxofcandidate = min(A[n-1] * B[min(k / n + 1, m - 1)], A[min(k / m + 1, n - 1)] * B[m - 1]);
		long long minofcandidate = max(A[0] * B[k/n - 1], A[k/m - 1] * B[0]);
		long long a = (minofcandidate + maxofcandidate) / 2;
		ans[i] = Finda(minofcandidate, a, maxofcandidate);
	}
	for (int i = 0; i < temp1; i++)
		cout << ans[i] << endl;
//	cout << (double)(clock()-start) / CLOCKS_PER_SEC<<endl;
	system("PAUSE");
	return 0;
}
