#include<iostream>

using namespace std;

struct Coord {
	long long x;
	long long y;
	long long weight;
};

Coord coorddata[100][100000];
Coord arr2[100000];
int len[100];
long long ans[100];
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
		Splity(arr1, arr2, 0, num, true); //false means arr1 is sorted
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

void CalcDistancex(Coord* data1, int len) {
	long long tot = 0;
	long long tmp = 0;
	for (int i = 0; i < len; i++) {
		tmp += data1[i].x;
	}
	if (len > 0)
	{
		tmp -= len * data1[0].x;
		data1[0].weight = tmp;
	}
	for (int i = 1; i < len; i++) {
		tmp += (len - 2 * i)*data1[i - 1].x;
		tmp -= (len - 2 * i)*data1[i].x;
		data1[i].weight = tmp;
	}
}

void CalcDistancey(Coord* data1, int len) {
	long long tot = 0;
	long long tmp = 0;
	for (int i = 0; i < len; i++) {
		tmp += data1[i].y;
	}
	if (len > 0)
	{
		tmp -= len * data1[0].y;
		data1[0].weight += tmp;
	}
	for (int i = 1; i < len; i++) {
		tmp += (len - 2 * i)*data1[i - 1].y;
		tmp -= (len - 2 * i)*data1[i].y;
		data1[i].weight += tmp;
	}
}

int main() {
	int num1;
	cin >> num1;
	for (int i = 0; i < num1; i++)
	{
		cin >> len[i];
		for (int j = 0; j < len[i]; j++)
		{
			cin >> coorddata[i][j].x >> coorddata[i][j].y;
		}
		Merge merge = Merge();
		merge.mergesortx(coorddata[i], len[i]);
		CalcDistancex(coorddata[i], len[i]);
		merge.mergesorty(coorddata[i], len[i]);
		CalcDistancey(coorddata[i], len[i]);
		
		long long temp = 0;
		if (len[i] > 0)
			temp = coorddata[i][0].weight;
		for (int j = 1; j < len[i]; j++)
		{
			if (temp > coorddata[i][j].weight)
				temp = coorddata[i][j].weight;
		}
		ans[i] = temp;
	}

	for (int i = 0; i < num1; i++)
		cout << ans[i] << endl;

	return 0;
}