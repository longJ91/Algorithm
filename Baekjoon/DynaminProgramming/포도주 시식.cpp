// ¹®Á¦ : https://www.acmicpc.net/problem/2156
// Botton Up
/**/
#include <iostream>
using namespace std;
long long R[10001][3] = { 0, };
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> R[i][0];
		R[i][1] = R[i][2] = R[i][0];
	}
	R[1][0] = 0;
	for (int i = 2; i <= N; i++) {
		long long temp;
		temp = R[i - 1][0];
		if (temp < R[i - 1][1]) temp = R[i - 1][1];
		if (temp < R[i - 1][2]) temp = R[i - 1][2];
		R[i][0] = temp + 0;
		R[i][2] = R[i - 1][1] + R[i][1];
		R[i][1] = R[i - 1][0] + R[i][1];
	}
	long long result;
	result = R[N][0];
	if (result < R[N][1]) result = R[N][1];
	if (result < R[N][2]) result = R[N][2];
	cout << result << endl;
	return 0;
}