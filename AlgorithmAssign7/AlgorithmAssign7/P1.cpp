/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int temp1;
int n_max, k;
struct triple {
public:
	int a1;
	int a2;
	int a3;
	triple(int x, int y, int z) {
		a1 = x;
		a2 = y;
		a3 = z;
	}
};
int x, y, z;
vector<triple> arr;
bool ans[1000];
bool isFound;
bool check(vector<triple>* arr, int n) {
	if (isFound == true)
		return true;
	if (arr->size() == 0)
		return true;
	if (n == n_max + 1)
		return false;
	int l = arr->size();
	vector<triple> arr1, arr2;
	for (int i = 0; i < l; i++) {
		if ((*arr)[i].a1 == 0 && (*arr)[i].a2 == 0 && (*arr)[i].a3 == 0)
			return false;
		if ((*arr)[i].a1 == n)
			arr2.push_back(triple((*arr)[i].a2, (*arr)[i].a3, 0));
		else if ((*arr)[i].a1 == -n)
			arr1.push_back(triple((*arr)[i].a2, (*arr)[i].a3, 0));
		else
		{
			arr1.push_back(triple((*arr)[i].a1, (*arr)[i].a2, (*arr)[i].a3));
			arr2.push_back(triple((*arr)[i].a1, (*arr)[i].a2, (*arr)[i].a3));
		}
	}
	if (arr1.size() == 0 || arr2.size() == 0)
	{
		isFound = true;
		return true;
	}
	return check(&arr1, n + 1) || check(&arr2, n + 1);
}
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		cin >> n_max >> k;
		for (int j = 0; j < k; j++) {
			cin >> x >> y >> z;
			if (x == -y || y == -z || x == -z)
				continue;
			if (x == y)
			{
				if (y == z)
					arr.push_back(triple(x, 0, 0));
				else
				{
					if (abs(x) <= abs(z))
						arr.push_back(triple(x, z, 0));
					else
						arr.push_back(triple(z, x, 0));
				}
				continue;
			}
			if (x == z)
			{
				if (abs(x) <= abs(y))
					arr.push_back(triple(x, y, 0));
				else
					arr.push_back(triple(y, x, 0));

				continue;
			}
			if (y == z)
			{
				if (abs(x) <= abs(z))
					arr.push_back(triple(x, z, 0));
				else
					arr.push_back(triple(z, x, 0));

				continue;
			}
			if (abs(x) <= abs(y) && abs(y) <= abs(z))
				arr.push_back(triple(x, y, z));
			else if (abs(x) <= abs(z) && abs(z) <= abs(y))
				arr.push_back(triple(x, z, y));
			else if (abs(y) <= abs(x) && abs(x) <= abs(z))
				arr.push_back(triple(y, x, z));
			else if (abs(y) <= abs(z) && abs(z) <= abs(x))
				arr.push_back(triple(y, z, x));
			else if (abs(z) <= abs(x) && abs(x) <= abs(y))
				arr.push_back(triple(z, x, y));
			else if (abs(z) <= abs(y) && abs(y) <= abs(x))
				arr.push_back(triple(z, y, x));
		}
		isFound = false;
		check(&arr, 1);
		ans[i] = isFound;
		arr.clear();
	}
	for (int i = 0; i < temp1; i++) {
		if (ans[i] == true)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
*/