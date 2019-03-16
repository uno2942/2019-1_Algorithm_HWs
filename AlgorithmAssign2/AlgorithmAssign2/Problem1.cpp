/*#include<iostream>
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
unsigned int addtwonum(unsigned long long a, unsigned long long b) {
	unsigned long long t = a + b;
	unsigned long long f1 = (t >> 31);
	unsigned long long b1 = t - (f1 << 31);
	return f1 + b1;
}
unsigned int multwonum(unsigned long long a, unsigned long long b) {
	unsigned long long t = a * b;
	unsigned long long f1 = (t >> 31);
	unsigned long long b1 = t - (f1 << 31);
	return f1 + b1;
}
unsigned int* mulmat(unsigned int* a, unsigned int* b) {
	unsigned int temp1 = addtwonum(multwonum(a[0], b[0]), multwonum(a[1], b[2]));
	unsigned int temp2 = addtwonum(multwonum(a[0], b[1]), multwonum(a[1], b[3]));
	unsigned int temp3 = addtwonum(multwonum(a[2], b[0]), multwonum(a[3], b[2]));
	unsigned int temp4 = addtwonum(multwonum(a[2], b[1]), multwonum(a[3], b[3]));
	a[0] = temp1;
	a[1] = temp2;
	a[2] = temp3;
	a[3] = temp4;
	if(a!=b)
		delete b;
	return a;
}
unsigned int* mulrec(unsigned int n) {
	if (n == 1)
		return (new unsigned int[4] { 1,1,1,0 });
	if(n==0)
		return (new unsigned int[4] { 1, 0, 0, 1 });
	else
	{
		unsigned int* a = mulrec(n/2);
		return mulmat(mulmat(a, a), mulrec(n % 2));
	}
}
unsigned int calc(unsigned int n) {
	unsigned int* a = mulrec(n-1);
	unsigned int temp = a[0];
	delete a;
	return temp;
}
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		cin >> temp[i];
	}

	for (int i = 0; i < temp1; i++) {
		
		cout << calc(temp[i])<<endl;
	}
	return 0;
}
*/