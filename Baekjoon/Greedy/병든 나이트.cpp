// ¹®Á¦ : https://www.acmicpc.net/problem/1783
// Greedy
#include <iostream>
using namespace std;
int main() {

	int N, M;
	cin >> N >> M;
	int result;
	if (N == 1) result = 1;
	else if (N == 2) {
		result = 1;
		if (M == 3 || M == 4) result++;
		else if (M == 5 || M == 6) result += 2;
		else if (M >= 7) result += 3;
	}
	else {
		result = 1;
		if (M == 2) result++;
		else if (M == 3) result += 2;
		else if (M == 4) result += 3;
		else if (M == 5 || M == 6 ) result += 3;
		else if (M == 7) result += 4;
		else {
			result += 4;
			result += (--M) - 6;
		}
	}
	cout << result;
	return 1;
}