/*#include<iostream>
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
	Line() {

	}
	Line(int _l, int _r, int _y)
	{
		l = _l;
		r = _r;
		y = _y;
	}
};

Line line[20][100][10000];
vector<Line> ans[20];
int temp[]
int len[20][100];
int num2[20];

int main() {
	int num1;
	cin >> num1;
	int l,r,y;
	for (int i = 0; i < num1; i++)
	{
		cin >> num2[i];
		for (int j = 0; j < num2[i]; j++) {
			cin >> l >> r >> y;
			line[i][y][len[i][y]].l = l;
			line[i][y][len[i][y]].r = r;
			len[i][y]++;
;		}
		for(int j=0; j<100; j++)
			sort(line[i][j], line[i][j]+len[i][j]);
	}
	for (int i = 0; i < num1; i++)
	{
		for (int k = 0; k < len[i][99]; k++)
			ans[i].push_back(Line(line[i][99][k].l, line[i][99][k].r, 99));
		for (int j = 98; j >= 0; j--) {
			for(int k=0; k<len[i][j]; k++)
				
		}
	}
	system("PAUSE");
	return 0;
}
*/