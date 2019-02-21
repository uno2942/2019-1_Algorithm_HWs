#include<iostream>

using namespace std;

struct Coord {
	long long x;
	long long y;
};

Coord coordOrigin[100][100000];
Coord coorddatax[100][100000];
Coord coorddatay[100][100000];
Coord arr2[100000];
long long len[100];
long long ansx[100];
long long ansy[100];

int CalcDistance(const long long* data1, int len, int index) {
	int tot = 0;
	int tmp = 0;
	for (int i = 0; i < len; i++) {
		tmp = data1[i] - data1[index];
		if (tmp > 0)
			tot += tmp;
		else
			tot -= tmp;
	}
	return tot;
}

class Merge {
public:
	static void mergesortx(Coord* arr1, int num) {
		for (int i = 0; i < num; i++)
			arr2[i] = arr1[i];
		Splitx(arr1, arr2, 0, num, true); //false means arr1 is sorted
	}

	static void mergesorty(Coord* arr1, int num) {
		for (int i = 0; i < num; i++)
			arr2[i] = arr1[i];
		Splitx(arr1, arr2, 0, num, true); //false means arr1 is sorted
	}
private:
	static void Splitx(Coord* arr1, Coord* arr2, int begin, int end, bool _whichArrayIsSorted) {
		if (end - begin < 2)
			return;
		int middle = (begin + end) / 2;
		Splitx(arr1, arr2, begin, middle, !_whichArrayIsSorted);
		Splitx(arr1, arr2, middle, end, !_whichArrayIsSorted);
		MergeWithSortx(arr1, arr2, begin, middle, end, _whichArrayIsSorted);
	}
	static void Splity(Coord* arr1, Coord* arr2, int begin, int end, bool _whichArrayIsSorted) {
		if (end - begin < 2)
			return;
		int middle = (begin + end) / 2;
		Splity(arr1, arr2, begin, middle, !_whichArrayIsSorted);
		Splity(arr1, arr2, middle, end, !_whichArrayIsSorted);
		MergeWithSorty(arr1, arr2, begin, middle, end, _whichArrayIsSorted);
	}

	static void MergeWithSortx(Coord* arr1, Coord* arr2, int begin, int middle, int end, bool _whichArrIsSorted) {
		if (_whichArrIsSorted)
		{
			Coord* temp = arr1;
			arr1 = arr2;
			arr2 = temp;
		}
		int i = begin;
		int j = middle;

		for (int k = begin; k < end; k++) {

			if (i < middle && (j >= end || arr1[i].x <= arr1[j].x))
			{
				arr2[k] = arr1[i];
				i++;
			}
			else
			{
				arr2[k] = arr1[j];
				j++;
			}
		}
	}

	static void MergeWithSorty(Coord* arr1, Coord* arr2, int begin, int middle, int end, bool _whichArrIsSorted) {
		if (_whichArrIsSorted)
		{
			Coord* temp = arr1;
			arr1 = arr2;
			arr2 = temp;
		}
		int i = begin;
		int j = middle;

		for (int k = begin; k < end; k++) {

			if (i < middle && (j >= end || arr1[i].y <= arr1[j].y))
			{
				arr2[k] = arr1[i];
				i++;
			}
			else
			{
				arr2[k] = arr1[j];
				j++;
			}
		}
	}
};

int main() {
	int num1;
	cin >> num1;
	for (int i = 0; i < num1; i++)
	{
		cin >> len[i];
		for (int j = 0; j < len[i]; j++)
		{
			cin >> coordOrigin[i][j].x >> coordOrigin[i][j].y;
			coorddatax[i][j] = coordOrigin[i][j];
		}
		Merge merge = Merge();
		merge.mergesortx(coorddatax[i], len[i]);
	}
	int i, j;
	for (i = 0; i < num1; i++) {
		for (j = 0; j < len[i]; j++)
		{
			if (coorddatax[i][len[i] / 2].x == coorddatay[i][j].x)
				break;
		}
		ansx[i] = j;
	}
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < len[i]; j++)
		{
			cout << mydatax[i][j] << ' ' << mydatay[i][j];
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}