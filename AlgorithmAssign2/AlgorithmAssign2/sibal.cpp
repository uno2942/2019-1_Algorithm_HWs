/*#include<iostream>
#include<algorithm>
using namespace std;
int temp1;
int temp2[100];
int temp3[100];
long long ylist[10000];
class Line {
public:
	long long l; //ALso startabouty
	long long r;
	long long y;
	long long vec; //Also Flag
	Line() {

	}
	Line(long long _l, long long _r, long long _y)
	{
		l = _l;
		r = _r;
		y = _y;
	}
};
bool Compare(Line a, Line b) { //If a has not bigger degree, return true
	if (a.y > b.y)
		return true;
	else if (a.y < b.y)
		return false;
	else {
		if (a.l < b.l)
			return true;
		else
			return false;
	}
}
Line arr1[10000];
Line arr2[10000];
void mergeline(int i) {
	int j = 1;
	int pivot = 0;
	int writingele = 0;
	arr2[writingele].l = arr1[0].l;
	arr2[writingele].y = arr1[0].y;
	while(j<temp2[i]) {
		if (arr1[pivot].y == arr1[j].y && arr1[pivot].r >= arr1[j].l)
		{
			if (arr1[pivot].r >= arr1[j].r) {
				j++;
				continue;
			}
			else {
				arr1[pivot].r = arr1[j].r;
				j++;
				continue;
			}
		}
		else
		{
			arr2[writingele].r = arr1[pivot].r;
			pivot = j;
			writingele++;
			arr2[writingele].l = arr1[pivot].l;
			arr2[writingele].y = arr1[pivot].y;
			j++;
		}
	}
	temp3[i] = writingele + 1;
}

void splitline(long long begin, long long end, int i) {
	splitline(begin, max(begin, arr2[i].l), i-1);
	splitline(min(end, arr2[i].r), end, i-1);
	()
}
int main() {
	cin >> temp1;

	int l, r, y, k;
	for (int i = 0; i < temp1; i++) {
		cin >> temp2[i];
		for (int j = 0; j < temp2[i]; j++) {
			cin >> arr1[j].l >> arr1[j].r >> arr1[j].y;
			ylist[j] = y;
		}
		sort(ylist, ylist + temp2[i]);
		mergeline(i);

	}
}
*/