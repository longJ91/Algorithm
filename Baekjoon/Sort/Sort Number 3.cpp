// ���� : https://www.acmicpc.net/problem/10989
// �迭�� Ȱ���� ���� �Լ��� ��� ���ؼ� O(N + 10000) ���⵵ ����
#include <iostream>
using namespace std;
int  number[10001] = { 0, };
int main() {
	int T, temp, count;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> temp;
		number[temp]++;
	}
	for (int i = 1; i < 10001; i++) {
		if (number[i] != 0) {
			count = number[i];
			for (int j = 0; j < count; j++) cout << i << "\n";
		}
	}
	return 1;
}