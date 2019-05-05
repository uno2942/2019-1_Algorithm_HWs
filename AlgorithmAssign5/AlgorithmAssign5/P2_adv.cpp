/*#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long temp1;
long long N;
long long x, y;
vector<pair<long long, long long>> points;
vector<pair<long long, long long>> ptbyY[300010];
long long horweight[300010];
long long verweight[300010];
long long vernext[300010];
long long potentialvernext[300010];
long long hornext[300010];
long long ans[101];
bool comparey(pair<long long, long long> p1, pair<long long, long long>p2) {
	return p1.second < p2.second;
}

vector<pair<long long, long long>>* dvq(long long y_min, long long y_max) {
	if (y_max - y_min == 0) {
		return &(ptbyY[y_min]);
	}
	long long y_mid = (y_min + y_max) / 2;

	vector<pair<long long, long long>>* upperres = dvq(y_mid + 1, y_max);
	vector<pair<long long, long long>>* lowerres = dvq(y_min, y_mid);
	vector<pair<long long, long long>>* res = new vector<pair<long long, long long>>();
	long long u_max = upperres->size();
	long long l_max = lowerres->size();
	long long upperpivot = u_max - 1;
	long long lowerpivot = l_max - 1;
	long long uppermaxpivot = u_max - 1;

	while (lowerpivot >= 0 && upperpivot > 0) {
		long long l = (*lowerres)[lowerpivot].first;
		long long r = (*upperres)[upperpivot].first;
		long long lowerindex = (*lowerres)[lowerpivot].second;
		long long upperindex = (*upperres)[upperpivot].second;
		if (hornext[lowerindex] != -1) {
			horweight[lowerindex] = max(verweight[hornext[lowerindex]], horweight[hornext[lowerindex]]) + 1;
		}
		if (max(verweight[upperindex], horweight[upperindex])
			>= max(verweight[(*upperres)[uppermaxpivot].second], horweight[(*upperres)[uppermaxpivot].second])
			) {
			uppermaxpivot = upperpivot;
		}
		if (l > r)
		{
			lowerpivot--;
			continue;
		}
		long long rnext = (*upperres)[upperpivot - 1].first;
		if(rnext < l) {
			if (vernext[lowerindex] == -1)
			{
				vernext[lowerindex] = (*upperres)[uppermaxpivot].second;
				verweight[lowerindex] = max(verweight[(*upperres)[uppermaxpivot].second], horweight[(*upperres)[uppermaxpivot].second]) + 1;
			}
			else
			{
				if (potentialvernext[lowerindex] == -1) {
					potentialvernext[lowerindex] = upperindex;
				}
				else
				{
					if (potentialvernext[lowerindex] >= upperindex)
						potentialvernext[lowerindex] = upperindex;
				}
				verweight[lowerindex] = max(verweight[vernext[lowerindex]], horweight[vernext[lowerindex]]) + 1;
				if (verweight[lowerindex] < max(verweight[(*upperres)[uppermaxpivot].second], horweight[(*upperres)[uppermaxpivot].second]) + 1) {
					vernext[lowerindex] = (*upperres)[uppermaxpivot].second;
					verweight[lowerindex] = max(verweight[(*upperres)[uppermaxpivot].second], horweight[(*upperres)[uppermaxpivot].second]) + 1;
				}
				else if (verweight[lowerindex] == max(verweight[(*upperres)[uppermaxpivot].second], horweight[(*upperres)[uppermaxpivot].second]) + 1
					&& (*upperres)[uppermaxpivot].first < points[vernext[lowerindex]].first)
				{
					vernext[lowerindex] = (*upperres)[uppermaxpivot].second;
				}
			}
			lowerpivot--;
		}
		else
			upperpivot--;

	}
	if (upperpivot == 0) {
		while (lowerpivot >= 0 && (*upperres)[upperpivot].first < (*lowerres)[lowerpivot].first) {
			lowerpivot--;
		}
		if (max(verweight[(*upperres)[upperpivot].second], horweight[(*upperres)[upperpivot].second])
			>= max(verweight[(*upperres)[uppermaxpivot].second], horweight[(*upperres)[uppermaxpivot].second])
			) {
			uppermaxpivot = upperpivot;
		}
		while (lowerpivot >= 0)
		{
			long long lowerindex = (*lowerres)[lowerpivot].second;
			if (hornext[lowerindex] != -1) {
				horweight[lowerindex] = max(verweight[hornext[lowerindex]], horweight[hornext[lowerindex]]) + 1;
			}
			if (vernext[lowerindex] == -1)
			{
				vernext[lowerindex] = (*upperres)[uppermaxpivot].second;
				verweight[lowerindex] = max(verweight[(*upperres)[uppermaxpivot].second], horweight[(*upperres)[uppermaxpivot].second]) + 1;
			}
			else
			{
				verweight[lowerindex] = max(verweight[vernext[lowerindex]], horweight[vernext[lowerindex]]) + 1;
				if (verweight[lowerindex] < max(verweight[(*upperres)[uppermaxpivot].second], horweight[(*upperres)[uppermaxpivot].second]) + 1) {
					vernext[lowerindex] = (*upperres)[uppermaxpivot].second;
					verweight[lowerindex] = max(verweight[(*upperres)[uppermaxpivot].second], horweight[(*upperres)[uppermaxpivot].second]) + 1;
				}
				else if (verweight[lowerindex] == max(verweight[(*upperres)[uppermaxpivot].second], horweight[(*upperres)[uppermaxpivot].second]) + 1
					&& (*upperres)[uppermaxpivot].first < points[vernext[lowerindex]].first)
				{
					vernext[lowerindex] = (*upperres)[uppermaxpivot].second;
				}
			}
			lowerpivot--;
		}
	}
	lowerpivot = 0;
	upperpivot = 0;
	while (upperpivot < u_max && lowerpivot < l_max) {
		long long l = (*lowerres)[lowerpivot].first;
		long long r = (*upperres)[upperpivot].first;
		if (l <= r)
		{
			res->push_back((*lowerres)[lowerpivot]);
			lowerpivot++;
		}
		else {
			res->push_back((*upperres)[upperpivot]);
			upperpivot++;
		}
	}
	if (upperpivot == u_max) {
		while (lowerpivot < l_max)
		{
			res->push_back((*lowerres)[lowerpivot]);
			lowerpivot++;
		}
	}
	else
	{
		while (upperpivot < u_max)
		{
			res->push_back((*upperres)[upperpivot]);
			upperpivot++;
		}
	}

	if (y_mid != y_min)
		delete lowerres;
	if (y_mid + 1 != y_max)
		delete upperres;
	return res;
}




int main() {
	cin >> temp1;
	long long y_now;
	long long ylabel;
	for (int i = 0; i < temp1; i++) {
		{
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> x >> y;
			points.push_back(make_pair(x, y));
		}
		stable_sort(points.begin(), points.end(), comparey);
		stable_sort(points.begin(), points.end());
		
		points.insert(points.begin(), make_pair(-1ll, -1ll));
		N++;
		
		for (int j = 0; j < N; j++) {
			points[j].first += j;
		}
		stable_sort(points.begin(), points.end(), comparey);
		y_now = points[N - 1].second + 1;
		for (int j = N - 1; j >= 0; j--) {
			if (y_now != points[j].second)
			{
				horweight[j] = 0;
				y_now = points[j].second;
				hornext[j] = -1;
			}
			else
			{
				horweight[j] = horweight[j + 1] + 1;
				hornext[j] = j+1;
			}
			vernext[j] = -1;
		}
		y_now = points[N - 1].second + 1;
		ylabel = -1;
		for (int j = 0; j < N ; j++) {
			if (y_now != points[j].second)
			{
				y_now = points[j].second;
				ylabel++;
				ptbyY[ylabel].push_back(make_pair(points[j].first, j));
			}
			else
				ptbyY[ylabel].push_back(make_pair(points[j].first, j));
		}
	}
		
		delete dvq(0, ylabel);
		ans[i] = max(horweight[0], verweight[0]);


		for (int j = 0; j < N ; j++) {
			horweight[j] = 0;
			verweight[j] = 0;
			hornext[j] = -1;
			vernext[j] = -1;
			ptbyY[j].clear();
		}
		points.clear();
	}
	for (int i = 0; i < temp1; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
*/