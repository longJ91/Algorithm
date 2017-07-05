// ¹®Á¦ : https://www.acmicpc.net/problem/2231
// 
#include <iostream>
using namespace std;
int getLen(int num) {
	int result = 0;
	while (num != 0) {
		num /= 10;
		result++;
	}
	return result;
}
int DS(int num) {
	int result = num, temp = num;
	while (temp != 0) {
		result += (temp % 10);
		temp /= 10;
	}
	return result;
}
int main() {
	int N;
	cin >> N;
	int len = getLen(N), i, min = 0;
	for (N-(9*len) < 0 ? i = 1 : i = N - (9 * len); i < N; i++){
		if (DS(i) == N) {
			min = i;
			break;
		}
	}
	cout << min << endl;
	return 0;
}