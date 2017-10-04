// ���� : https://www.acmicpc.net/problem/10972
// ex - ����
#include <iostream>
#include <algorithm>
#include <vector>
/*
STL ���� �Լ��� ����� ���� ǥ��
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
// ���� ����
/*
�迭 ũ�Ⱑ N�� ���, 
1. A[i-1] < A[i] �� �����ϴ� ���� ū i�� ã�´�.
2. A[i-1] < A[j] �� �����ϴ� ���� ū j�� ã�´�. (j >= i)
3. swap(A[j], A[i-1]) ���� �ٲ��ش�.
4. i ��°���� ������ �ε������� �������ش�.
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