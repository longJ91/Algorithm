// 문제 : https://www.acmicpc.net/problem/13458
// 삼성 SW 기출
// 23분 걸림
#include <iostream>
using namespace std;
unsigned long long result = 0;
int room[1000000];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> room[i];
	int B, C;
	cin >> B >> C;
	for (int i = 0; i < N; i++) {
		room[i] -= B;
		result++;
	}
	for (int i = 0; i < N; i++) {
		if (room[i] > 0) {
			int temp;
			if (room[i] % C == 0) temp = room[i] / C;
			else temp = (room[i] / C) + 1;
			result += temp;
		}
	}
	cout << result;
	return 1;
}