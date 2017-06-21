// ¹®Á¦ : https://www.acmicpc.net/problem/2110
// Binary Search
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int N, C;
	cin >> N >> C;
	vector<int> house(N);
	for (int i = 0; i < N; i++) cin >> house[i];
	sort(house.begin(), house.end());
	unsigned long left = 1, right = 1000000000, mid;
	int max = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		int cnt = 0, pre;
		for (int i = 0; i < N; i++){
			int distance;
			if (i == 0) {
				pre = house.at(i);
				cnt++;
				continue;
			}
			distance = house.at(i) - pre;
			if (distance >= mid) {
				pre = house.at(i);
				cnt++;
				continue;
			}
		}
		if (cnt < C) {
			right = mid - 1;
			continue;
		}
		else {
			left = mid + 1;
			max < mid ? max = mid : 0;
			continue;
		}
	}
	cout << max << endl;
	return 0;
}