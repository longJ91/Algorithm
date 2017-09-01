// ¹®Á¦ : https://www.acmicpc.net/problem/11047
// Greedy
#include <iostream>
using namespace std;
int cash[10];
int main() {

	int N, K, result = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> cash[i];
	for (int i = N-1; i >= 0; i--) {
		if (K >= cash[i]) {
			result += K / cash[i];
			K %= cash[i];
		}
	}
	cout << result;
	return 1;
}