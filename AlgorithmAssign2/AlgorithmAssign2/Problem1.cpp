#include<iostream>
#include<algorithm>
using namespace std;

int temp1;
unsigned int nummax = 0;
unsigned int temp[1000];
unsigned int ans[3];

struct Sorttemp {
	unsigned int n;
	int i;
	unsigned int ans;
	bool operator <(const Sorttemp& d) {
		if (this->n < d.n) {
			return true;
		}
		else
			return false;
	}
};
bool compi(Sorttemp a, Sorttemp b) {
	if (a.i < b.i)
		return true;
	else
		return false;
}
Sorttemp sorttemp[1000];
unsigned int addtwonum(unsigned int a, unsigned int b) {
	unsigned int t = a + b;
	unsigned int f1 = (t >> 31);
	unsigned int b1 = t - (f1 << 31);
	return f1 + b1;
	/*	unsigned f1, f2, b1, b2;
	f1 = (a >> 16);
	f2 = (b >> 16);
	b1 = a - (f1 << 16);
	b2 = b - (f1 << 16);
//	long long t1 = b1 * f2 - (((b1*f2) >> 16) << 16);
//	((f1*f2)<<1)+((b1*f2+f1*b2)<<16)
	long long preans2 = ((f1*f2) << 1) + ((b1*f2 + f1 * b2) << 16) + b1 * b2;
	long long preans = (preans2 >> 32) + (preans2 - ((preans2 >> 32) << 32));
	return preans;
	*/
}
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		cin >> temp[i];
		sorttemp[i].n = temp[i];
		sorttemp[i].i = i;
	}
	sort(sorttemp, sorttemp + temp1);
	nummax = sorttemp[temp1 - 1].n;
	int j = 0;
	ans[0] = 1;
	ans[1] = 1;
	for (; j < temp1; j++) {
		if (sorttemp[j].n == 1)
			sorttemp[j].ans = 1;
		else if (sorttemp[j].n == 2)
			sorttemp[j].ans = 1;
		else
			break;
	}
	for (int i = 2; i < nummax; i++)
	{
		ans[2] = addtwonum(ans[1], ans[0]);
		ans[0] = ans[1];
		ans[1] = ans[2];
		while (sorttemp[j].n == (i + 1))
		{
			sorttemp[j].ans = ans[2];
			j++;
			if (j == temp1)
				goto E;
		}
	}
	E:
	sort(sorttemp, sorttemp + temp1, compi);
	for (int i = 0; i < temp1; i++) {
		cout <<sorttemp[i].ans<<endl;
	}
	system("PAUSE");
	return 0;
}