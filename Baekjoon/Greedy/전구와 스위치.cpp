// ¹®Á¦ : https://www.acmicpc.net/problem/2138
// Greedy
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void change(vector<int> &a, int index) {
	for (int i = index - 1; i <= index + 1; i++) {
		if (0 <= i && i < a.size()) a[i] == 1 ? a[i] = 0 : a[i] = 1;
	}
}
pair<bool, int>go(vector<int> a, vector<int> &b) {
	int count = 0, len = a.size();
	for (int i = 0; i < len - 1; i++) {
		if (a[i] != b[i]) {
			change(a, i + 1);
			count++;
		}
	}
	int flag = 1;
	for (int i = 0; i<len; i++) {
		if (a[i] != b[i]) {
			flag = -1;
			break;
		}
	}
	if (flag == 1) return make_pair(true, count);
	else return make_pair(false, count);
}
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	vector<int> b(N);
	for (int i = 0; i < N; i++) scanf("%1d", &a[i]);
	for (int i = 0; i < N; i++) scanf("%1d", &b[i]);
	pair<bool, int> result1 = go(a, b);
	change(a, 0);
	pair<bool, int> result2 = go(a, b);
	if (result2.first) result2.second++;
	if (result1.first && result2.first) cout << min(result1.second, result2.second);
	else if (result1.first) cout << result1.second;
	else if (result2.first) cout << result2.second;
	else cout << -1;
	return 1;
}