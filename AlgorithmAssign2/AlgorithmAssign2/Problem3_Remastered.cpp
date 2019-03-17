/**/#include<iostream>
#include<algorithm>
using namespace std;
long long temp1;
long long temp2[1000];
int Flag[100];
long long startabouty[100];
class Line {
public:
	int l;
	int r;
	int y;
	char vec;
	Line() {

	}
	Line(int _l, int _r, int _y)
	{
		l = _l;
		r = _r;
		y = _y;
	}
};

Line arr1[100][20000];

bool Compare(Line a, Line b) { //If a has not bigger degree, return true
	if (a.l < b.l)
		return true;
	else if (a.l > b.l)
		return false;
	else {
		if (a.y > b.y)
			return true;
		else
			return false;
	}
}
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		cin >> temp2[i];
		for (int j = 0; j < temp2[i]; j++) {
			cin >> arr1[i][2 * j].l >> arr1[i][2 * j].r >> arr1[i][2 * j].y;
			arr1[i][2 * j].y--;
			arr1[i][2 * j].vec = 1;
			arr1[i][2 * j + 1].l = arr1[i][2 * j].r;
			arr1[i][2 * j + 1].r = arr1[i][2 * j].l;
			arr1[i][2 * j + 1].y = arr1[i][2 * j].y;
			arr1[i][2 * j + 1].vec = -1;
		}
		sort(arr1[i], arr1[i] + 2 * temp2[i], Compare);
	}
	for (int i = 0; i < temp1; i++) {
		long long top = -1;
		long long prevpoint = -1;
		for (int j = 0; j < 100; j++)
		{
			Flag[j] = 0;
			startabouty[j] = 0;
		}
		for (int j = 0; j < 2 * temp2[i]; j++) {
			if (j == 2 * temp2[i]) {
				if (top != -1)
					cout << startabouty[top] << ' ' << arr1[i][j - 1].l << ' ' << top + 1 << endl;
				break;
			}
			if (prevpoint != arr1[i][j].l) {

				if (top != -1 && Flag[top] == 0)
				{
					cout << startabouty[top] << ' ' << prevpoint << ' ' << top + 1 << endl;
					for (int q = 0; q < top; q++)
						startabouty[q] = prevpoint;
					top = -1;
				}
				int k = 99;
				while (k >= 0 && Flag[k] == 0) //binary search?
					k--;
				if (top < k)
				{
					if (top != -1)
					{
						cout << startabouty[top] << ' ' << prevpoint << ' ' << top + 1 << endl;
						startabouty[k] = prevpoint;
					}
					top = k;
				}

				prevpoint = arr1[i][j].l;
			}

			Flag[arr1[i][j].y] += arr1[i][j].vec;
			if (Flag[arr1[i][j].y] == 1 && arr1[i][j].vec == 1)
				startabouty[arr1[i][j].y] = arr1[i][j].l;
		}
	}
	system("PAUSE");
	return 0;
}