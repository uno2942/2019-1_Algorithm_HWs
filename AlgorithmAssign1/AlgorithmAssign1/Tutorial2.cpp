/*#include<iostream>

using namespace std;

class Merge {
public:
	static void mergesort(int* arr1, int num) {
		int* arr2 = new int[num];
		for (int i = 0; i < num; i++)
			arr2[i] = arr1[i];
		Split(arr1, arr2, 0, num ,true); //false means arr1 is sorted
	}

private:
	static void Split(int* arr1, int* arr2, int begin, int end, bool _whichArrayIsSorted) {
		if (end - begin < 2)
			return;
		int middle = (begin + end) / 2;
		Split(arr1, arr2, begin, middle, !_whichArrayIsSorted);
		Split(arr1, arr2, middle, end, !_whichArrayIsSorted);
		MergeWithSort(arr1, arr2, begin, middle, end, _whichArrayIsSorted);
	}
	static void MergeWithSort(int* arr1, int* arr2, int begin, int middle, int end, bool _whichArrIsSorted) {
		if (_whichArrIsSorted)
		{
			int* temp = arr1;
			arr1 = arr2;
			arr2 = temp;
		}
		int i = begin;
		int j = middle;

		for (int k = begin; k < end; k++) {

			if (i < middle && (j >= end || arr1[i] <= arr1[j]))
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
	int** data = new int*[num1];
	int* len = new int[num1];
	for (int i = 0; i < num1; i++)
	{
		cin >> len[i];
		data[i] = new int[len[i]];
		for (int j = 0; j < len[i]; j++)
			cin >> data[i][j];
		Merge merge = Merge();
		merge.mergesort(data[i], len[i]);
	}
	for (int i = 0; i < num1; i++)
	{
		for(int j=0; j< len[i]; j++)
			cout << data[i][j]<<' ';
		cout << endl;
	}
	return 0;
}
*/