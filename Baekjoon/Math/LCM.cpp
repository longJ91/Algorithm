// 문제 : https://www.acmicpc.net/problem/1934
// GCD 값을 활용
#include <iostream>
using namespace std;
int GCD(int x, int y) {
	if (y == 0) return x;
	else return GCD(y, x%y);
}
int main() {
	int T,A,B;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A; cin >> B;
		int g = GCD(A, B);
		cout <<  A*B/g << "\n";
	}
	return 1;
}