// ¹®Á¦ : https://www.acmicpc.net/problem/2515
// dp
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//0 - sum, 1 - high
int dp[300001][2];
bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
	if (a.first < b.first) return true;
	if (a.first == b.first) return a.second > b.second;
	return false;
}
int binarySearch(const int n, const int s, const vector<pair<int,int>> &p) {
	int left = 0, right = n - 1;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (p[n].first - p[mid].first >= s) left = mid + 1;
		else right = mid - 1;
	}
	return right;
}
int main() {

	int n, s;
	cin >> n >> s;
	int h, c;
	vector<pair<int, int>> picture(n + 1);
	picture[0] = make_pair(0, 0);
	for (int i = 1; i <= n; i++) {
		//cin >> h >> c;
		scanf("%d%d", &h, &c);
		picture[i] = make_pair(h, c);
	}
	sort(picture.begin(), picture.end(),cmp);
	dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i <= n; i++) {
		if (picture[i].first - dp[i - 1][1] >= s) {
			dp[i][0] = dp[i - 1][0] + picture[i].second;
			dp[i][1] = picture[i].first;
		}
		else {
			int prev;
			prev = binarySearch(i, s, picture);
			if (dp[i-1][0] < picture[i].second + dp[prev][0]) {
				dp[i][0] = picture[i].second + dp[prev][0];
				dp[i][1] = picture[i].first;
			}
			else {
				dp[i][0] = dp[i - 1][0];
				dp[i][1] = dp[i - 1][1];
			}
		}
	}

	cout << dp[n][0] << endl;
	return 1;
}