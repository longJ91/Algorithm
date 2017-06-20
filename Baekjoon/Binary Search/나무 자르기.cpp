// ¹®Á¦ : https://www.acmicpc.net/problem/2805
// Binary Search
#include <iostream>
using namespace std;
unsigned long long tree[1000000];
int main() {
	unsigned long long N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> tree[i];
	unsigned long long left, right, mid, temp, max = 0;
	left = 1; right = 1000000000;
	while (left <= right) {
		temp = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < N; i++) tree[i] > mid ? temp += tree[i] - mid: 0;
		if (temp < M) right = mid - 1;
		else {
			if (max < mid) max = mid;
			left = mid + 1;
		}
	}
	cout << max << endl;
	return 0;
}