// ���� : https://www.acmicpc.net/problem/1676
// 0�� ��Ÿ���� ������ 5 * 2�� ���ؼ� �߻�. ���⼭ 2�� 5���� ���� ������ ������ 5�� ������ ���ش�. ��, 5�� ������ �� �� 25ó�� 5�� 2�� �̻� ������ ���� �߰��� ī��Ʈ �ؾ� �Ѵ�.
#include <iostream>
using namespace std;
int main() {
	int N, R = 0;
	cin >> N;
	if (N >= 5) R += N / 5;
	if (N >= 25) R += N / 25;
	if (N >= 125) R += N / 125;
	cout << R;
	return 0;
}