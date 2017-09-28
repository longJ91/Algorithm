// ���� : https://www.acmicpc.net/problem/2315
// dp
/*
���� �̷��� Ǫ�� �ֵ� �밡���� �ñ�...
��¡���� ó���� ��ġ�ϴ� ���ε� ��ȣ�� �־����Ƿ� ���⼭���� �����ϸ� �˴ϴ�.
���⼭ ��¡���� ���ε�� ���ε� ���̿��� ������ �ٲ� �ʿ�� ���� ������,
��¡���� �������� �濡 �ִ� ���ε��� �ݵ�� �� �� ���� �ִٰ� �߷��� �� �ֽ��ϴ�.

�׷��ٸ� DP�� ������ Ǯ �� �� ������ �κ� ������ ��� �����ؾ� �ұ��?



�ϴ� M��°�� ���ε��� ���� �����մϴ�.

minimumElecWaste(left, right, onWhichSide)
���� ���������� ���� �ִ� ���ε��� ���� left��,
������ ���������� ���� �ִ� ���ε��� ���� right���̰�,
��¡���� ���� onWhichSide(���� Ȥ�� ������)�� �ִ� ���
���ݺ��� ����Ǵ� ������ �ּڰ�

���ε��� �ݵ�� ���� ����������, �׸��� ������ ���������͸� ���� �ִ� �����̸�
����� ���� �ִ� ���ε���� �����ϴ� ���¶�� ���� �� �� �ִµ�
��¡���� ������ ���� ���ε��� �ݵ�� ���� ���� �̵��̱� �����Դϴ�.

�κ� ������ ���� ��ʴ� left�� right�� ��� 0�� ��� ���� 0�̶� ���Դϴ�.
�׷��ٸ� �� ���� ���, ��¡���� ������ ���ε��� �ϳ� �� ����,
�������� ���ε��� �ϳ� �� ������ �����ؾ� �ϴµ�
�̰� �� �κ� ������ Ǯ�� ���� �� �� ���� ���� ã���� �� ���Դϴ�.
�̶�, �̵��ϴ� �� ��� �ð��� �� ���ؼ� ���� ���ε� ���� ���ؼ� ���� �ָ�
��¡���� ���� ���ε��� ���� ���� �̵��ϴ� ���� �Ҹ�Ǵ� ������ �˴ϴ�.

minimumElecWaste(left, right, onWhichSide) =
if(left+right == 0) then 0
else then min(
minElecWaste(left-1, right, ����) + ����Ǵ� ����,
minElecWaste(left, right-1, ������) + ����Ǵ� ����
)

�������� ���� ����̰�, �ƴϸ� �Ķ����� �ʷϻ� �� �ּҰ��� ���� �Ǵµ�
�� ��쿡 ���ؾ� �ϴ� "����Ǵ� ����" ����
���� onWhichSide�� �����̳� �������̳Ŀ� ���� �ſ� �ٸ��ϴ�.



DP�� ���� �˾�ä�� �κ� ������ �����ϴ� �͵� ��¦ �������
�� ������ ���� �Ӹ� ���� �� �ִ� ����.
�迭 �ε����� ���̰ų�, �߸��� ���� ����Ѵٰų� �ϴ� �Ǽ��� �Ͼ �� �ֽ��ϴ�.

N�� �ִ� 1000�̹Ƿ� �κ� ������ ������ 1000 * 1000 * 2�� �˴ϴ�.
�� �κ� ������ Ǫ�� ���� O(1)�� �ð��� �ɸ��Ƿ�
��ü �ð� ���⵵�� O(N^2)�Դϴ�.

��ó (���� 20�� Ŭ�� ����)- http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220553198516&parentCategoryNo=&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 2000000000;
using namespace std;
int N, M, D[1001], W[1001], wSum[1001], dp[1001][1001][2];

int go(const int left, const int right, bool onRight) {
	int &result = dp[left][right][onRight];
	if (result != -1) return result;
	if (left == 0 && right == 0) return result = 0;
	
	result = MAX;

	if (left) {
		result = go(left - 1, right, false) + ((wSum[left] + wSum[N] - wSum[N - right]) * (onRight ? D[N - right - 1] - D[left - 1] : D[left] - D[left - 1]));
	}
	if (right) {
		result = min(result, go(left, right - 1, true) + ((wSum[left] + wSum[N] - wSum[N - right]) * (onRight ? D[N - right] - D[N - right - 1]: D[N-right] - D[left])));
	}
	return result;
}
int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		//cin >> D[i] >> W[i];
		scanf("%d%d", D + i, W + i);
		wSum[i + 1] = wSum[i] + W[i];
	}
	cout << go(M - 1, N - M, false) << endl;
	return 1;
}