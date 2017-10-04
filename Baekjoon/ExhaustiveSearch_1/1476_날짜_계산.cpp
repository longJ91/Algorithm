// 문제 : https://www.acmicpc.net/problem/1476
// 완전탐색
#include <iostream>
using namespace std;
int E, S, M;
int ans = 1;
int e, s, m;
int main() {
	e = s = m = 0;
	cin >> E >> S >> M;
	E--; S--; M--;
	while (!(E == e && S == s && M == m)) {
		e++; s++; m++; ans++;
		e %= 15;
		s %= 28;
		m %= 19;
	}
	cout << ans << endl;
	return 1;
}