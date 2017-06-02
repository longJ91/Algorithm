// ���� : https://www.acmicpc.net/problem/2089
// ���� ���� ��ȯ�� ����. ��, �������� ������ ������ �ʰ� �����ϱ�
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main() {
	int N, temp;
	string result = "";
	cin >> N;
	if (N == 0) result = "0";
	while (N != 0) {
		if (N % 2 == 0) {
			N /= -2;
			result += "0";
		}
		else {
			if (N > 0) N /= -2;
			else N = (-N + 1) / 2;
			result += "1";
		}
	}
	reverse(result.begin(),result.end());
	cout << result;

	return 0;
}