#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
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
vector<Line> linevec[20][100];
int num[1000000];
int num2[20];
int indexes[20000];
int leftmost;
int rightmost;

int main() {
	int num1;
	cin >> num1;
	int l,r,y;
	for (int i = 0; i < num1; i++)
	{
		cin >> num2[i];
		for (int j = 0; j < num2[i]; j++) {
			cin >> l >> r >> y;
			linevec[i][y].push_back(Line(l, r));
;		}
		for(int j=0; j<100; j++)
			sort(linevec[i][j].begin(), linevec[i][j].end());
	}
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < 100; j++) {
			cout << linelist[i][j].l << ' ' << linelist[i][j].r << ' ' << linelist[i][j].y << endl;
		}
	}
	system("PAUSE");
	return 0;
}