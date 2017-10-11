// 문제 : https://www.acmicpc.net/problem/12846
// 히스토그램 최대 직사각형 비슷한 유형 (세그먼트 트리)- 구현
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first < b.first;
}
int n;
int ans;
int list[100000];
vector<pair<int, int> > list_index;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> list[i];
		list_index.push_back(make_pair(list[i], i));
	}
	sort(list_index.begin(), list_index.end(), cmp);
	int prev = ans = 0;
	for (auto it = list_index.begin(); it != list_index.end(); ++it) {
		if (prev == (*it).first) continue;
		if (it == list_index.begin()) {
			ans = (*it).first * n;
			prev = (*it).first;
		}
		else {
			int min_v = (*it).first;
			prev = min_v;
			int min_index = (*lower_bound(list_index.begin(), list_index.end(), *it, cmp)).second;
			int left, right;
			left = min_index - 1;
			right = min_index + 1;
			for (int l = left; l >= 0; l--) {
				if (list[l] < min_v) {
					left = l;
					break;
				}
				if (l == 0) left = 0;
			}
			for (int r = right; r < n; r++) {
				if (list[r] < min_v) {
					right = r;
					break;
				}
				if (r == n - 1) right = n - 1;
			}
			ans = max(ans, ((right - left - 1)*min_v));
		}
	}
	cout << ans << endl;
	return 1;
}