#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int score[101];
int main() {
	for (int t = 0; t < 10; t++) {
		int test_case = -1, s;
		cin >> test_case;
		if (test_case == -1) break;
		memset(score, 0, sizeof(score));
		for (int i = 1; i <= 1000; i++) {
			cin >> s;
			score[s]++;
		}
		int index = -1, max_value = 0;
		for (int i = 100; i >= 0; i--) {
			if (max_value < score[i]) {
				max_value = score[i];
				index = i;
			}
		}
		cout << "#" << test_case << " " << index << "\n";
	}
	return 0;
}