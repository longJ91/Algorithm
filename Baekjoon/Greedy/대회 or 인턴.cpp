// ¹®Á¦ : https://www.acmicpc.net/problem/2875
// Greedy
#include <iostream>
using namespace std;
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	int result = 0;
	while (N >= 2 && M >= 1) {
		result++;
		N -= 2;
		M--;
	}
	if (result == 0) {
		cout << 0;
		return 1;
	}
	if (N + M < K) {
		K -= N + M;
		if (K % 3 == 0) result -= (K / 3);
		else result -= (K / 3) + 1;
	}
	cout << result;
	return 1;
}