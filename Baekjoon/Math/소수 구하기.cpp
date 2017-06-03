// 문제 : https://www.acmicpc.net/problem/1929
// 에라토스테네스의 체 활용
#include <iostream>
using namespace std;
int P[1000000];
int PN = 0;
bool check[1000000];
int main() {
	int M, N;
	cin >> M >> N;
	for (int i = 2; i <= N; i++) {
		if (check[i] == false) {
			P[PN++] = i;
			for (int j = i * 2; j <= N; j+=i) {
				check[j] = true;
			}
		}
	}
	for (int i = 0; i < PN; i++) {
		if(P[i] >= M) cout << P[i] << "\n";
	}

	return 0;
}