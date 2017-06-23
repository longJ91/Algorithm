// ¹®Á¦ : https://www.acmicpc.net/problem/1912
//
#include <iostream>
using namespace std;
int A[100001];
long long D[100001];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		D[i] = A[i];
		if (i == 1) continue;
		if (D[i - 1] + A[i] > A[i]) D[i] = D[i - 1] + A[i];
	}
	long long max = D[1];
	for (int i = 2; i <= N; i++) if (max < D[i]) max = D[i];
	cout << max << endl;
	return 0;
}