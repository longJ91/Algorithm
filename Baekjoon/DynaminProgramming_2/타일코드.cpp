// ���� : https://www.acmicpc.net/problem/1720
// dp
// ��ü ����� �� �߿� �¿� ��Ī ������ ���� 2���� ������.
// (��ü + �¿��Ī ��) / 2 �� ���ָ� ���� 2���� �����ϴ� �ߺ��� ���ŵ�
#include <iostream>
using namespace std;
int N;
unsigned long all[31];
unsigned long dp[31];
int main() {
	cin >> N;
	all[1] = 1;
	all[2] = 3;
	for (int i = 3; i <= N; i++) all[i] = all[i - 1] + (all[i - 2] * 2);
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= N; i++) {
		unsigned long temp;
		if (!(i & 1)) temp = all[i / 2] + (all[(i - 2) / 2] * 2);
		else temp = all[(i - 1) / 2];
		dp[i] = (all[i] + temp) / 2;
	}
	cout << dp[N] << endl;
	return 1;
}