// 문제 : https://www.acmicpc.net/problem/2309
// 완전탐색
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n = 9;
vector<int> tall(9);
int result[7];
void find(const int count, const int index) {
	if (count == 8) {
		int sum = 0;
		for (int i = 0; i < 7; i++) sum += result[i];
		if (sum == 100) {
			for (int i = 0; i < 7; i++) cout << result[i] << "\n";
			exit(0);
		}
		return;
	}
	for (int i = index; i < n; i++) {
		result[count - 1] = tall[i];
		find(count + 1, i + 1);
	}
}
int main() {
	for (int i = 0; i < n; i++) cin >> tall[i];
	sort(tall.begin(), tall.end());
	find(1, 0);
	return 1;
}