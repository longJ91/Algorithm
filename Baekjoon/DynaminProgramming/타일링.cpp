// 문제 : https://www.acmicpc.net/problem/11726
// 규칙을 활용
#include <iostream>
using namespace std;
long long R[1001];
int main() {
	int N;
	cin >> N;
	R[1] = 1;
	R[2] = 2;
	for (int i = 3; i <= N; i++) {
		R[i] = R[i - 1] + R[i - 2];
		R[i] = R[i] % 10007;
	}
	cout << R[N] << endl;
	return 0;
}