#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

class Line {
public:
	int l;
	int r;
	int y;
	
	bool operator <(const Line &a) const {
		return this->l < a.l;
	}
};
Line linelist[100][10000];
int num[1000000];
int num2[100];
bool compare(Line a, Line b) {
	if (a.y <= b.y)
		return false;
	else
		return true;
}
int main() {
	int num1;
	
	cin >> num1;
	for (int i = 0; i < num1; i++)
	{
		cin >> num2[i];
		for (int j = 0; j < num2[i]; j++) {
			cin >> linelist[i][j].l >> linelist[i][j].r >> linelist[i][j].y;
		}

		sort(linelist[i], linelist[i] + num2[i]);
	}
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num2[i]; j++) {
			cout << linelist[i][j].l << ' ' << linelist[i][j].r << ' ' << linelist[i][j].y << endl;
		}
	}
	system("PAUSE");
	return 0;
}