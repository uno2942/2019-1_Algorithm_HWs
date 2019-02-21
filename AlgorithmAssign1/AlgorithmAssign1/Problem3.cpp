/*#include<iostream>

using namespace std;

long long num[1000000];
int Calcnum(long long n) {
	long long i;
	long long temp;
	for (i = 0; i < 65537; i++)
	{
		temp = (2 * i + 1)*(2 * i + 1);
		if (temp - n >= 0)
			break;
	}
	return i;
}

int main() {
	int num1;
	cin >> num1;
	for (int i = 0; i < num1; i++)
	{
		cin >> num[i];
	}
	long long temp;
	long long biggestnum;
	long long smallnum;
	long long middle;
	for (int i = 0; i < num1; i++)
	{
		temp = Calcnum(num[i]);
		biggestnum = (2 * temp + 1)*(2 * temp + 1);
		smallnum = (2 * (temp - 1) + 1)*(2 * (temp - 1) + 1);
		middle = (biggestnum + smallnum ) / 2;

		
		if (middle < num[i])
		{
			if (biggestnum - (2 * temp + 1) < num[i]) //west
				cout << -temp << ' ' << temp - (biggestnum - num[i]);
			else//south
				cout << temp - (num[i] - middle) << ' ' << -temp;
		}
		else {
			if (smallnum + 2 * temp <= num[i])//east
				cout << temp << ' ' << -temp + (middle - num[i]);
			else//Nuclear
				cout << -temp + (num[i] - smallnum) << ' ' << temp;
		}
		cout << endl;
	}
	return 0;
}
*/