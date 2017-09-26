// ¹®Á¦ : https://www.acmicpc.net/problem/1947
// dp
#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;
	unsigned long long dp_1, dp_2;
	dp_1 = 0, dp_2 = 1;
	unsigned long long temp;
	for (int i = 3; i <= n; i++) {
		temp = (i - 1) * (dp_1 + dp_2) % 1000000000;
		dp_1 = dp_2;
		dp_2 = temp;
	}
	if (n == 1) dp_2 = 0;
	if (n == 2) dp_2 = 1;
	cout << dp_2 % 1000000000 << endl;
	return 1;
}