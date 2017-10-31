#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int num[12];
int N, max_result, min_result;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	vector<int> cal;
	for (int i = 0; i < 4; i++) {
		int temp;
		cin >> temp;
		for (int k = 0; k < temp; k++) {
			cal.push_back(i);
		}
	}
	max_result = -987654321;
	min_result = 987654321;
	int r;
	r = num[0];
	for (int i = 0; i < N - 1; i++) {
		int C = cal[i];
		if (C == 0) {
			r += num[i + 1];
		}
		else if (C == 1) {
			r -= num[i + 1];
		}
		else if (C == 2) {
			r *= num[i + 1];
		}
		else if (C == 3) {
			r /= num[i + 1];
		}
	}
	max_result = max(max_result, r);
	min_result = min(min_result, r);
	while (next_permutation(cal.begin(), cal.end())) {
		int r;
		r = num[0];
		for (int i = 0; i < N - 1; i++) {
			int C = cal[i];
			if (C == 0) {
				r += num[i + 1];
			}
			else if (C == 1) {
				r -= num[i + 1];
			}
			else if (C == 2) {
				r *= num[i + 1];
			}
			else if (C == 3) {
				r /= num[i + 1];
			}
		}
		max_result = max(max_result, r);
		min_result = min(min_result, r);
	}
	cout << max_result << "\n" << min_result << endl;
	return 0;
}