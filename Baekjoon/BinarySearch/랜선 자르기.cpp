// 문제 : https://www.acmicpc.net/problem/1654
// 이분 완전 탐색
#include <iostream>
#include <math.h>
using namespace std;
unsigned long len[10001];
int main() {
	int K, N;
	cin >> K >> N;
	for (int i = 0; i < K; i++) cin >> len[i];
	unsigned long result = 0, L, R;
	L = 1; R = pow(2, 31) - 1;
	while (L <= R) {
		unsigned long temp = 0, mid;
		mid = (L + R) / 2;
		for (int i = 0; i < K; i++){
			temp += len[i] / mid;
		}
		if (temp >= N) {
			mid > result ? result = mid : 0;
			L = mid + 1;
			continue;
		}
		else if (temp < N) {
			R = mid - 1;
			continue;
		}
	}
	cout << result << endl;
	return 0;
}