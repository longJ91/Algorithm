// 문제 : https://www.acmicpc.net/problem/2315
// dp
/*
레알 이런거 푸는 애들 대가리가 궁금...
마징가가 처음에 위치하는 가로등 번호가 주어지므로 여기서부터 시작하면 됩니다.
여기서 마징가가 가로등과 가로등 사이에서 방향을 바꿀 필요는 절대 없으며,
마징가가 지나가는 길에 있는 가로등은 반드시 그 뒤 꺼져 있다고 추론할 수 있습니다.

그렇다면 DP로 문제를 풀 때 이 문제의 부분 문제는 어떻게 정의해야 할까요?



일단 M번째의 가로등은 끄고 시작합니다.

minimumElecWaste(left, right, onWhichSide)
왼쪽 끝에서부터 켜져 있는 가로등의 수가 left개,
오른쪽 끝에서부터 켜져 있는 가로등의 수가 right개이고,
마징가가 현재 onWhichSide(왼쪽 혹은 오른쪽)에 있는 경우
지금부터 낭비되는 전력의 최솟값

가로등을 반드시 왼쪽 끝에서부터, 그리고 오른쪽 끝에서부터만 켜져 있는 형태이며
가운데는 꺼져 있는 가로등들이 연속하는 형태라는 것을 알 수 있는데
마징가가 지나간 길의 가로등은 반드시 끄는 것이 이득이기 때문입니다.

부분 문제의 기저 사례는 left와 right이 모두 0인 경우 답이 0이란 것입니다.
그렇다면 그 외의 경우, 마징가가 왼쪽의 가로등을 하나 더 끌지,
오른쪽의 가로등을 하나 더 끌지를 결정해야 하는데
이건 두 부분 문제를 풀어 보고 둘 중 적은 쪽을 찾으면 될 것입니다.
이때, 이동하는 데 드는 시간을 잘 구해서 남은 가로등 수와 곱해서 더해 주면
마징가가 다음 가로등을 끄기 위해 이동하는 동안 소모되는 전력이 됩니다.

minimumElecWaste(left, right, onWhichSide) =
if(left+right == 0) then 0
else then min(
minElecWaste(left-1, right, 왼쪽) + 낭비되는 전력,
minElecWaste(left, right-1, 오른쪽) + 낭비되는 전력
)

빨간색이 기저 사례이고, 아니면 파란색과 초록색 중 최소값이 답이 되는데
각 경우에 더해야 하는 "낭비되는 전력" 값이
현재 onWhichSide가 왼쪽이냐 오른쪽이냐에 따라 매우 다릅니다.



DP인 것을 알아채고 부분 문제를 정의하는 것도 살짝 어렵지만
그 구현도 조금 머리 아플 수 있는 문제.
배열 인덱스가 꼬이거나, 잘못된 값을 계산한다거나 하는 실수가 일어날 수 있습니다.

N이 최대 1000이므로 부분 문제의 개수는 1000 * 1000 * 2가 됩니다.
각 부분 문제를 푸는 데는 O(1)의 시간이 걸리므로
전체 시간 복잡도는 O(N^2)입니다.

출처 (백준 20위 클라스 ㄷㄷ)- http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220553198516&parentCategoryNo=&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView
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