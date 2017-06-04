// ¹®Á¦ : https://www.acmicpc.net/problem/10872
#include <iostream>
using namespace std;
int main() {
	long N,R = 1;
	cin >> N;
	for (int i = 1; i <= N; i++) R *= i;
	if (N == 0) cout << 1;
	else cout << R;
	return 0;
}