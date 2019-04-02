#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>

using namespace std;

int coords[100000];
int s;
int beg, fin, k, temp;
int binarysearch(int data) {
	beg = 0;
	fin = s;
	while (beg <= fin) {
		k = (beg + fin) / 2;
		if (data < coords[k])
			fin = k - 1;
		else
			beg = k + 1;
	}
	return k;
}
void inserttoproperindex(int data) {
	coords[s++]=data;
	k = binarysearch(data);
	temp = coords[k];
	coords[k] = data;
	coords
}
int main() {

}