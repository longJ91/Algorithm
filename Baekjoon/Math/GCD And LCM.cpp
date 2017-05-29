// ���� : https://www.acmicpc.net/problem/2609
// GCD & LCM �� ���Ѵ�. LCM�� GCD�� Ȱ���ؼ� ���Ѵ�. A*B/G
#include <iostream>
using namespace std;
int GCD(int A, int B) {
	int r;
	r = A % B;
	while (r != 0) {
		r = A % B;
		A = B;
		B = r;
	}
	return A;
}
int LCM(int A, int B, int G) {
	return (A*B / G);
}
int main() {
	int A, B;
	cin >> A; cin >> B;
	cout << GCD(A, B) << "\n" << LCM(A, B, GCD(A, B));
	return 1;
}