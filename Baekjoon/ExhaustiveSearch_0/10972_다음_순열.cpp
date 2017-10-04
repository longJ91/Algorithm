// 문제 : https://www.acmicpc.net/problem/10972
// ex - 순열
#include <iostream>
#include <algorithm>
#include <vector>
/*
STL 내장 함수를 사용해 순열 표현
using namespace std;
int N;
int permutation[10000];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> permutation[i];
	}
	bool flag = next_permutation(permutation, permutation + N);
	if (flag != false) {
		for (int i = 0; i < N; i++) {
			cout << permutation[i] << " ";
		}
	}
	else cout << -1 << endl;
	
	return 1;
}
*/
// 직접 구현
/*
배열 크기가 N일 경우, 
1. A[i-1] < A[i] 를 만족하는 가장 큰 i를 찾는다.
2. A[i-1] < A[j] 를 만족하는 가장 큰 j를 찾는다. (j >= i)
3. swap(A[j], A[i-1]) 서로 바꿔준다.
4. i 번째부터 마지막 인덱스까지 뒤집어준다.
*/
using namespace std;
int N;
int permutation[10000];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> permutation[i];
	}
	bool flag = true;
	int i = N - 1;
	while (i > 0 && permutation[i] <= permutation[i - 1]) i--;
	if (i == 0) flag = false;
	else {
		int j = N - 1;
		while (permutation[i - 1] >= permutation[j]) j--;
		swap(permutation[j], permutation[i - 1]);
		j = N - 1;
		while (i < j) swap(permutation[i++], permutation[j--]);
	}
	if (flag != false) {
		for (int i = 0; i < N; i++) {
			cout << permutation[i] << " ";
		}
	}
	else cout << -1 << endl;
	return 1;
}