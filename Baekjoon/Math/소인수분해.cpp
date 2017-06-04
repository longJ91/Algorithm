// 문제 : https://www.acmicpc.net/problem/11653
// 소인수분해 : 정수 N을 소수의 곱으로 표현. 소인수분해 한 인수 중 가장 큰 값은 루트 N 이므로 루트 N 까지 나누어 떨어지지 않을때 까지 N을 나눈다.
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	for (int i = 2; i * i <= N; i++) {
		while (N % i == 0) {
			cout << i << "\n";
			N /= i;
		}
	}
	if (N > 1) cout << N << endl;
	return 0;
}