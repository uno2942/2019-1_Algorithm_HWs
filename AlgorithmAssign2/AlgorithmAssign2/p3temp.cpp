/*
#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

class Line {
public:
	int l;
	int r;
	int y;
	bool operator <(const Line &a) const {
		return this->l < a.l;
	}
	Line() {

	}
	Line(int _l, int _r, int _y)
	{
		l = _l;
		r = _r;
		y = _y;
	}
};

class mytype {
public:
	int n;
	int y;
	bool operator <(const Line &a) const {
		return this->n < a.n;
	}
};
mytype line[20][20000];
vector<Line> ans[20];
int num2[20];
int main() {
	int num1;
	cin >> num1;
	int l, r, y;
	for (int i = 0; i < num1; i++)
	{
		cin >> num2[i];
		for (int j = 0; j < num2[i]; j++) {
			cin >> l >> r >> y;
			line[i][2 * j].n = l;
			line[i][2 * j].y = -y;
			line[i][2 * j + 1].n = r;
			line[i][2 * j + 1].n = y;

		}
		sort(line[i], line[i] + 2*num2[i]);
	}
	merge()
	for (int i = 0; i < num1; i++)
	{
		for (int j = 100; j >= 1; j--)
		{
			int flag = 0;
			int prevflag = 0;
			int start = -1;
			bool drawflag = false;
			for (int k = 0; k < 2 * num2[i]; k++) {
				if (abs(line[i][k].n) > j)
					flag++;
				if (line[i][k].y == j)
					start = line[i][k].n;
				if (flag == 0)
					drawflag = true;
				else
					drawflag = false;
				prevflag = flag;
			}
		}
	}
	system("PAUSE");
	return 0;
}
*/