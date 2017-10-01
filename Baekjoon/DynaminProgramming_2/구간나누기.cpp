// ���� : https://www.acmicpc.net/problem/2228
// dp
/*
DP

������ ���� �� ���� ��� ������ ���캸�� 6���� ���� �� 2���� ������ ������ �Ѵ�.
�̶� ���� ������ �����ϸ鼭 ���� �ִ밡 �Ǵ� ���� { -1, 3, 1, 2, 4, -1 } �� ����̴�.

�� ������ DP�� Ǯ ��
DP[n][m] = n���� ���ҵ��� ���տ��� m���� �������� �������� �� ���� �ִ밪

1. i�� ° ���� �������� �ʴ� ���
�̴� i - 1������ ���ҵ��� ���տ��� ���� m���� ���� ���� �ִ밪�� ����.
-> dp[i][m] =dp[i - 1][m]

2. i�� ° ���� �����ϴ� ���
i�� ° ���� �����ϴ� ������ m��° ������ �Ǿ�� �ϸ�
������ m - 1������ ������� ���� �ִ밪�� ���Ͽ��� �Ѵ�.
�� ��, i��° ���� �����ϴ� ������ ���������� ��������� �𸥴�.
���� �ݺ����� ���� ��� ��츦 ã�ƺ��� �� �� �ִ밪�� ã�� ���Ͽ� �ش�.

��, Max(dp[k - 2][m - 1] + Sum(data[k ~ i])


��ó: http://ksj14.tistory.com/entry/BeakJoon2228-����-������ [:: ENJOY ::]
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
const int M_MAX = -2000000000;
using namespace std;
int N, M;
int cost[101];
int psum[101];
int cost_dp[101][51];
bool check_dp[101][51];
int go(const int n, const int m) {
	if (m == 0) return 0;
	if (n < 0) return M_MAX;
	int &ret = cost_dp[n][m];
	if (check_dp[n][m]) return ret;
	check_dp[n][m] = true;
	ret = go(n - 1, m);
	for (int i = n; i > 0; i--) {
		int temp = go(i - 2, m - 1) + psum[n] - psum[i - 1];
		ret = max(ret, temp);
	}
	return ret;
}
int main() {
	cin >> N >> M;
	psum[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		psum[i] = psum[i - 1] + cost[i];
	}
	cout << go(N, M) << endl;
	return 1;
}