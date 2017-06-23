// ¹®Á¦ : https://www.acmicpc.net/problem/11055
// Botton Up
#include <iostream>
using namespace std;
int A[1001];
long long D[1001];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		D[i] = A[i];
		for (int j = 1; j < i; j++) if (A[i] > A[j] && D[i] < D[j] + A[i]) D[i] = D[j] + A[i];
	}
	long long max;
	max = D[1];
	for (int i = 2; i <= N; i++) if (max < D[i]) max = D[i];
	cout << max << endl;
	return 0;
}