// 문제 : https://www.acmicpc.net/problem/10974
// 모든 순열 - STL permutation 함수를 이용
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int permutation[8];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) permutation[i - 1] = i;
	bool flag = true;
	while (flag) {
		for (int i = 0; i < N; i++) cout << permutation[i] << " ";
		cout << "\n";
		flag = next_permutation(permutation, permutation + N);
	}
	return 1;
}