// ¹®Á¦ : https://www.acmicpc.net/problem/5612
#include <iostream>
using namespace std;
int main() {
	int	n, m, max;
	cin >> n >> m;
	max = m;
	for (int i = 0; i < n; i++){
		int in, out;
		cin >> in >> out;
		m += in;
		m -= out;
		if (m < 0) {
			max = 0;
			break;
		}
		if (max < m) max = m;
	}
	cout << max << endl;
	return 0;
}