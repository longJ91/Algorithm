// ¹®Á¦ : https://www.acmicpc.net/problem/14658
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, L, K;
bool cmp(const pair<int, int> a, const pair<int, int> b) {
	if (a.first < b.first) return true;
	return false;
}
int main() {
	cin >> N >> M >> L >> K;
	int x, y;
	vector< pair<int, int> > star;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		star.push_back(make_pair(x, y));
	}
	sort(star.begin(), star.end(), cmp);
	//L++;
	int ans = K;
	for (int i = 0; i < K; i++) {
		int first_x = star[i].first;
		for (int j = i + 1; j < K; j++) {
			int temp_x = star[j].first;
			if (temp_x - first_x <= L && j != K - 1) continue;
			if (j == K - 1 && temp_x - first_x <= L) j++;
			int second_x = star[j - 1].first;
			vector<int> star_y;
			for (int a = i; a <= j - 1; a++) star_y.push_back(star[a].second);
			sort(star_y.begin(), star_y.end());
			int star_y_size = star_y.size();
			for (int a = 0; a < star_y_size; a++) {
				int first_y = star_y[a];
				for (int b = a + 1; b < star_y_size; b++) {
					int temp_y = star_y[b];
					if (temp_y - first_y <= L && b != star_y_size - 1) continue;
					if (b == star_y_size - 1 && temp_y - first_y <= L) b++;
					ans = min(ans, K - (((b - 1) - a) + 1));
					break;
				}
			}
			break;
		}
	}
	cout << ans << endl;
	return 1;
}