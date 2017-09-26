// ¹®Á¦ : https://www.acmicpc.net/problem/5721
// dp
#include <iostream>
int dp_m[100000];
int dp_n[100000];
using namespace std;
int cmp(const int a, const int b) {
	if (a > b) return a;
	return b;
}
int main() {

	int m, n, temp;
	while (true) {
		cin >> m >> n;
		if (m == 0 && n == 0) break;
		int result = 0;
		for (int i = 0; i < m; i++) {
			int max_n = 0;
			for (int j = 0; j < n; j++) {
				cin >> temp;
				dp_n[j] = temp;
				if (j == 2) {
					dp_n[j] += dp_n[j - 2];
				}
				else if (j > 2) {
					dp_n[j] += cmp(dp_n[j-2], dp_n[j-3]);
				}
				dp_n[j] > max_n ? max_n = dp_n[j] : 0;
			}
			dp_m[i] = max_n;
			if (i == 2) {
				dp_m[i] += dp_m[i - 2];
			}
			else if (i > 2) {
				dp_m[i] += cmp(dp_m[i-2], dp_m[i-3]);
			}
			dp_m[i] > result ? result = dp_m[i] : 0;
		}
		cout << result << "\n";
	}

	return 1;
}