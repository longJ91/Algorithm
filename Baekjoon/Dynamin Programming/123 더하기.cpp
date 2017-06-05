// ¹®Á¦ : https://www.acmicpc.net/problem/9095
//
#include <iostream>
using namespace std;
int R[12];
int main() {
	int T, N;
	cin >> T;
	R[1] = 1;
	R[2] = 2;
	R[3] = 4;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 4; j <= N; j++) if (!(R[j] > 0)) R[j] = R[j - 1] + R[j - 2] + R[j - 3];
		cout << R[N] << "\n";
	}

	return 0;
}