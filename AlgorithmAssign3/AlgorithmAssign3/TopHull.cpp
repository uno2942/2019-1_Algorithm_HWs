#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long temp1;
long long temp2[100];
struct mydata {
	long long l;
	long long r;
	long long h;
	mydata(long long _l, long long _r, long long _h) {
		l = _l;
		r = _r;
		h = _h;
	}
};
bool compare(const mydata& d1, const mydata& d2) {
	return d1.h > d2.h;
}
vector<mydata> coords;
vector<pair<long long, long long>>* ans[100];
vector<pair<long long, long long>>* merge(vector<pair<long long, long long>>* A, vector<pair<long long, long long>>* B) {
	vector<pair<long long, long long>>* temp = new vector<pair<long long, long long>>();
	long long pivotA = 0;
	long long pivotB = 0;
	long long nowhA = 0;
	long long nowhB = 0;
	if ((*A)[pivotA].first < (*B)[pivotB].first)
	{
		temp->push_back(make_pair((*A)[pivotA].first, (*A)[pivotA].second));
		nowhA = (*A)[pivotA].second;
		pivotA++;
	}
	else if ((*A)[pivotA].first > (*B)[pivotB].first) {
		temp->push_back(make_pair((*B)[pivotB].first, (*B)[pivotB].second));
		nowhB = (*B)[pivotB].second;
		pivotB++;
	}
	else {
		if ((*A)[pivotA].second >= (*B)[pivotB].second) {
			temp->push_back(make_pair((*A)[pivotA].first, (*A)[pivotA].second));
			nowhA = (*A)[pivotA].second;
			pivotA++;
		}
		else
		{
			temp->push_back(make_pair((*B)[pivotB].first, (*B)[pivotB].second));
			nowhB = (*B)[pivotB].second;
			pivotB++;
		}
	}
	while (pivotA < A->size() && pivotB < B->size()) {
		if ((*A)[pivotA].first == (*B)[pivotB].first && (*A)[pivotA].second == (*B)[pivotB].second)
			pivotB++;

		if ((*A)[pivotA].first <= (*B)[pivotB].first)
		{
			if (nowhB >= (*A)[pivotA].second && nowhB!=0) {
				if (nowhA > nowhB)
					temp->push_back(make_pair((*A)[pivotA].first, max((*A)[pivotA].second, nowhB)));
				nowhA = (*A)[pivotA].second;
				pivotA++;
				continue;
			}
			nowhA = (*A)[pivotA].second;
			temp->push_back(make_pair((*A)[pivotA].first, (*A)[pivotA].second));
			pivotA++;
		}
		else if ((*A)[pivotA].first > (*B)[pivotB].first) {
			if (nowhA >= (*B)[pivotB].second && nowhA != 0) {
				if(nowhB>nowhA)
					temp->push_back(make_pair((*B)[pivotB].first, max((*B)[pivotB].second, nowhA)));
				nowhB = (*B)[pivotB].second;
				pivotB++;
				continue;
			}
			nowhB = (*B)[pivotB].second;
			temp->push_back(make_pair((*B)[pivotB].first, (*B)[pivotB].second ));
			pivotB++;
		}
	}
	if (pivotA == A->size())
	{
		while (pivotB < B->size())
		{
			temp->push_back(make_pair((*B)[pivotB].first, (*B)[pivotB].second));
			pivotB++;
		}
	}
	else if (pivotB == B->size())
	{
		while (pivotA < A->size())
		{
			temp->push_back(make_pair((*A)[pivotA].first, (*A)[pivotA].second));
			pivotA++;
		}
	}
	delete A;
	delete B;
	return temp;
}
vector<pair<long long, long long>>* solve(long long beg, long long end) {
	if (end - beg == 1)
	{
		vector<pair<long long, long long>>* temp = new vector<pair<long long, long long>>();
		temp->push_back(make_pair(coords[beg].l, coords[beg].h));
		temp->push_back(make_pair(coords[beg].r, 0));
		return temp;
	}
	long long mid = (beg + end) / 2;
	vector<pair<long long, long long>>* A = solve(beg, mid);
	vector<pair<long long, long long>>* B = solve(mid, end);
	return merge(A, B);
}
int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		cin >> temp2[i];
		int l, r, h;
		for (int j = 0; j < temp2[i]; j++) {
			cin >> l >> r >> h;
			coords.push_back(mydata(l, r, h));
		}
		ans[i] = solve(0, coords.size());
		coords.clear();
	}
	for (int i = 0; i < temp1; i++) {
		for (int j = 0; j < ans[i]->size(); j++)
		{
			cout << (*ans[i])[j].first << ' ' << (*ans[i])[j].second << endl;
		}
		delete ans[i];
	}
	system("PAUSE");
	return 0;
}