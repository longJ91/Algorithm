// 문제 : https://www.acmicpc.net/problem/6603
// 완전 탐색 - 순열
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int S[13];
int k;

void select(const int countOfNumber, const int index, vector<int> set) {
	if (countOfNumber == 7) {
		for (int i = 0; i < 6; i++) printf("%d ", set[i]);
		printf("\n");
		return;
	}
	if (6 - (countOfNumber - 1) > k - index) return;
	for (int i = index; i < k; i++) {
		set[countOfNumber - 1] = S[i];
		select(countOfNumber + 1, i + 1, set);
	}
}

int main() {
	while (true) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) cin >> S[i];
		vector<int> set(6);
		select(1, 0, set);
		printf("\n");
	}
	return 1;
}