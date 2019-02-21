#include<iostream>

using namespace std;

long long num[1000000];
int Calcnum(long long n) {
	long long i;
	long long temp;
	for (i = 0; i < 50000; i++)
	{
		temp = (2 * i + 1)*(2 * i + 1);
		if (temp < 0 || temp - n >= 0)
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
	long long diff;
	long long biggestnum;
	long long smallnum;
	long long middle;
	for (int i = 0; i < num1; i++)
	{
		temp = Calcnum(num[i]);
		biggestnum = (2 * temp + 1)*(2 * temp + 1);
		smallnum = (2 * (temp - 1) + 1)*(2 * (temp - 1) + 1);
		middle = (biggestnum * biggestnum + smallnum * smallnum)/2;
		if (biggestnum < 0)
		{

			continue;
		}
		else {
			diff = biggestnum * biggestnum - num[i];
			if (middle < num[i])
			{
				if (biggestnum - (2 * temp + 1) < num[i])
					cout << -temp << ' ' << temp - diff;
				else
					cout << temp - (num[i] - middle) << ' ' << -2;
			}
			else {

			}
		}
	}
	return 0;
}