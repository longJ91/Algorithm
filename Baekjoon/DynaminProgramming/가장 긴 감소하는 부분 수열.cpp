// ¹®Á¦ : https://www.acmicpc.net/problem/11722
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
		D[i] = 1;
		for (int j = 1; j <= i; j++) if (A[i] < A[j] && D[i] < D[j] + 1) D[i] = D[j] + 1;
	}
	long long max = 0;
	for (int i = 1; i <= N; i++) if (max < D[i]) max = D[i];
	cout << max << endl;
	return 0;
}