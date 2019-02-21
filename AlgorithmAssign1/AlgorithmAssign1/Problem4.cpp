#include<iostream>
#include<cstdlib>
using namespace std;

struct Coord {
	long long x;
	long long y;
};

Coord coordOrigin[100][100000];
//Coord coorddatax[100][100000];
//Coord coorddatay[100][100000];
//Coord arr2[100000];
long long len[100];
long long ans[100];
//long long ansx[100];
//long long ansy[100];

long long CalcDistance2(const Coord* data1, int len, int index, long long bound) {
	long long tot = 0;
	for (int i = 0; i < len; i++) {
		tot += (abs(data1[i].x - data1[index].x) + abs(data1[i].y - data1[index].y));
		if (tot-bound>0)
			return tot;
	}
	return tot;
}
long long CalcDistance1(const Coord* data1, int len, int index) {
	long long tot = 0;
	for (int i = 0; i < len; i++) {
		tot += (abs(data1[i].x - data1[index].x) + abs(data1[i].y - data1[index].y));
	}
	return tot;
}
/*
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
*/
int main() {
	int num1;
	cin >> num1;
	for (int i = 0; i < num1; i++)
	{
		cin >> len[i];
		for (int j = 0; j < len[i]; j++)
		{
			cin >> coordOrigin[i][j].x >> coordOrigin[i][j].y;
		}
	}
	
	int i, j;
	long long temp1 = 0;
	long long temp2 = 0;
	
	for (i = 0; i < num1; i++) {
		temp1= CalcDistance1(coordOrigin[i], len[i], 0);
		for (j = 1; j < len[i]; j++)
		{
			temp2 = CalcDistance2(coordOrigin[i], len[i], j, temp1);
			if (temp1 > temp2)
			{
				temp1 = temp2;
			}
		}
		ans[i] = temp1;
	}
	for (int i = 0; i < num1; i++)
	{
			cout << ans[i];
			cout << endl;
	}
	return 0;
}