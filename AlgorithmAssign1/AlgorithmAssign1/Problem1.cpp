/*#include<iostream>

using namespace std;

struct Coord {
	long long x;
	long long y;
};
class Merge {
public:
	static void mergesort(Coord* arr1, int num) {
		Coord* arr2 = new Coord[num];
		for (int i = 0; i < num; i++)
			arr2[i] = arr1[i];
		Split(arr1, arr2, 0, num, true); //false means arr1 is sorted
	}

private:
	static void Split(Coord* arr1, Coord* arr2, int begin, int end, bool _whichArrayIsSorted) {
		if (end - begin < 2)
			return;
		int middle = (begin + end) / 2;
		Split(arr1, arr2, begin, middle, !_whichArrayIsSorted);
		Split(arr1, arr2, middle, end, !_whichArrayIsSorted);
		MergeWithSort(arr1, arr2, begin, middle, end, _whichArrayIsSorted);
	}
	static void MergeWithSort(Coord* arr1, Coord* arr2, int begin, int middle, int end, bool _whichArrIsSorted) {
		if (_whichArrIsSorted)
		{
			Coord* temp = arr1;
			arr1 = arr2;
			arr2 = temp;
		}
		int i = begin;
		int j = middle;

		for (int k = begin; k < end; k++) {

			if (i < middle && (j >= end || Compare(arr1[i], arr1[j])))
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

	static bool Compare(Coord a, Coord b) { //If a has not bigger degree, return true
		
		if (a.x >= 0 && b.x < 0)
			return true;
		else if (b.x >= 0 && a.x < 0)
			return false;
		else if (b.x == 0 && a.x == 0) {
			if ((a.y <= b.y && a.y>=0) || (b.y<0 && a.y >= 0) || (a.y<0 && b.y<0 && a.y>=b.y))
				return true;
			return false;
		}
		long long res = a.x*b.y - a.y*b.x;
		if (res < 0)
			return true;
		else if (res > 0)
			return false;
		else
		{
			if (a.x * a.x + a.y * a.y<= b.x * b.x + b.y * b.y)
				return true;
			return false;
		}
	}
};

int main() {
	int num1;
	cin >> num1;
	Coord** data = new Coord*[num1];
	int* len = new int[num1];
	for (int i = 0; i < num1; i++)
	{
		cin >> len[i];
		data[i] = new Coord[len[i]];
		for (int j = 0; j < len[i]; j++)
			cin >> data[i][j].x >> data[i][j].y;
		Merge merge = Merge();
		merge.mergesort(data[i], len[i]);
	}
	cout << endl;
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < len[i]; j++)
		{
			cout << data[i][j].x << ' ' << data[i][j].y;
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
*/