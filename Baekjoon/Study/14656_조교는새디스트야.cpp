// ¹®Á¦ : https://www.acmicpc.net/problem/14656
#include <iostream>
using namespace std;
int N, temp;
int main() {
	cin >> N;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		if (temp != i) ans++;
	}
	cout << ans << endl;
	return 1;
}