// ���� : https://www.acmicpc.net/problem/11653
// ���μ����� : ���� N�� �Ҽ��� ������ ǥ��. ���μ����� �� �μ� �� ���� ū ���� ��Ʈ N �̹Ƿ� ��Ʈ N ���� ������ �������� ������ ���� N�� ������.
#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	for (int i = 2; i * i <= N; i++) {
		while (N % i == 0) {
			cout << i << "\n";
			N /= i;
		}
	}
	if (N > 1) cout << N << endl;
	return 0;
}