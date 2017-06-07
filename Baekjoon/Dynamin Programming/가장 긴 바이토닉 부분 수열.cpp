// 문제 : https://www.acmicpc.net/problem/11054
// Botton Up and 발생 Case 별로 나눠서 체크
#include <iostream>
using namespace std;
int A[1001];
long long D[1001][2];
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		D[i][0] = D[i][1] = 1;
		for (int j = 1; j <= i; j++) {
			if (A[i] > A[j] && D[i][1] < D[j][1] + 1) D[i][1] = D[j][1] + 1;
			if (A[i] < A[j] && D[i][0] < D[j][1] + 1) D[i][0] = D[j][1] + 1;
			if (A[i] < A[j] && D[i][0] < D[j][0] + 1) D[i][0] = D[j][0] + 1;
		}
	}
	long long max = 0;
	for (int i = 1; i <= N; i++) {
		if (max < D[i][0]) max = D[i][0];
		if (max < D[i][1]) max = D[i][1];
	}
	cout << max << endl;
	return 0;
}