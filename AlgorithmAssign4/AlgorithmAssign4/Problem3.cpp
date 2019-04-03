#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
struct compare {
	bool operator()(const int& a, const int& b) const { return a > b; }
};

set<long long> leftcoordsset;
set<long long, compare> rightcoordsset;
pair<long long, long long> leftcoords[100001];
pair<long long, long long> rightcoords[100001];
vector<long long> hlist;
long long s1, s2;
long long temp1;
long long ans[100];
long long anstemp;
long long n, w;
long long l, r, lrw;
long long segleft, segright;
long long leftmost, rightleast;

int main() {
	cin >> temp1;
	for (int i = 0; i < temp1; i++) {
		cin >> n >> w;
		for (int j = 0; j < n; j++) {
			cin >> l >> r >> lrw;
			leftcoords[j] = make_pair(lrw, l);
			rightcoords[j] = make_pair(lrw, r);
			hlist.push_back(lrw);
		}

		sort(leftcoords, leftcoords + n);
		sort(rightcoords, rightcoords + n);
		sort(hlist.begin(), hlist.end());
		anstemp = hlist[0] * w;
		s1 = 0;
		s2 = 0;
		leftmost = 0;
		rightleast = w;
		while (leftcoords[s1].first == hlist[0] && s1<n) {
			if (leftmost < leftcoords[s1].second)
				leftmost = leftcoords[s1].second;
			leftcoordsset.insert(leftcoords[s1].second);
			if (rightleast > rightcoords[s1].second)
				rightleast = rightcoords[s1].second;
			rightcoordsset.insert(rightcoords[s1].second);
			s1++;
		}
		s2 = s1;
		for (int j = 1; j < hlist.size(); j++) {
			if (s1 == n)
				break;
			while (leftcoords[s2].first == hlist[j] && s2 < n)
			{
				if (leftmost < leftcoords[s2].second)
				{
					segleft = *rightcoordsset.lower_bound(leftcoords[s2].second);
					segright = w;
					if (anstemp < (segright - segleft)*hlist[j])
						anstemp = (segright - segleft)*hlist[j];
					while (leftcoords[s2].first == hlist[j] && s2 < n)
					{
						leftmost = leftcoords[s2].second;
						s2++;
					}
					while (s1 < s2)
					{
						leftcoordsset.insert(leftcoords[s1].second);
						rightcoordsset.insert(rightcoords[s1].second);
						s1++;
					}
					break;
				}
				else
					segright = *leftcoordsset.lower_bound(leftcoords[s2].second);



				if (rightleast > rightcoords[s2].second)
				{
					segleft = 0;
					segright = *leftcoordsset.lower_bound(rightcoords[s2].second);;
					if (anstemp < (segright - segleft)*hlist[j])
						anstemp = (segright - segleft)*hlist[j];

					int rightleasttemp = rightleast;
					rightleast = rightcoords[s2].second;
					while (rightcoords[s2].second < rightleasttemp && s2 < n)
					{
						s2++;
					}
					continue;
				}
				else
					segleft = *rightcoordsset.lower_bound(rightcoords[s2].second);

				if (anstemp < (segright - segleft)*hlist[j])
					anstemp = (segright - segleft)*hlist[j];
				s2++;
			}
			while (s1 < s2) {
				leftcoordsset.insert(leftcoords[s1].second);
				rightcoordsset.insert(rightcoords[s1].second);
				s1++;
			}
		}
		hlist.clear();
		leftcoordsset.clear();
		rightcoordsset.clear();
		ans[i] = anstemp;
	}
	for (int i = 0; i < temp1; i++)
		cout << ans[i] << endl;
	system("PAUSE");
	return 0;
}