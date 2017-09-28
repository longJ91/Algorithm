// 문제 : https://www.acmicpc.net/problem/1328
// dp
/*
dp[n][l][r] -> n : 건물의 수     l : 왼쪽에서 봤을 때 빌딩의 수    r : 오른쪽에서 봤을 때 빌딩의 수
n - 1 건물의 수의 상태에서 건물을 추가하여 경우의 수를 구해나가는 과정
이때, 길이 n 번째 건물을 추가하여 경우의 수를 따지기보다 길이 1의 건물을 추가한다고 생각하면 점화식을 구하기 쉽다.

예를 들어, 3개의 건물 2, 3, 4가 존재 할 때
l , r
234    3, 1
324    2, 1
243    2, 2
342    2, 2
423    1, 2
432    1, 3

이 경우에 길이 1인 건물을 추가해 보자
1. 맨 앞에 추가하기    -> l + 1이 된다.
l , r
1 234    4, 1
1 324    3, 1
1 243    3, 2
1 342    3, 2
1 423    2, 2
1 432    2, 3

2. 맨 뒤에 추가하기    -> r + 1이 된다.
l , r
234 1    3, 2
324 1    2, 2
243 1    2, 3
342 1    2, 3
423 1    1, 3
432 1    1, 4

3. 그 외 아무데나 추가하기    -> 변화 없음
l , r                        l , r
2134    3, 1        2314    3, 1
3124    2, 1        3214    2, 1
3124    2, 1        3214    2, 1
3142    2, 2        3412    2, 2
4123    1, 2        4213    1, 2
4132    1, 3        4312    1, 3

따라서 점화식을 세우면
dp[n][l][r] = dp[n - 1][l][r] * (n - 2) + dp[n - 1][l - 1][r] + dp[n - 1][l][r + 1]이다.

또한 dp[n][1][n] = dp[n][n][1] = 1로 각각 오름차순과 내림차순으로 정렬되어 있을 경우 나올 수 있는 값이며 경우의 수 이다.


출처: http://ksj14.tistory.com/entry/BackJoon1328-고층-빌딩 [:: ENJOY ::]
*/
#include <iostream>
using namespace std;
#define mod 1000000007
int n, l, r;
unsigned long dp[101][101][101];
int main() {
	cin >> n >> l >> r;
	dp[1][1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int left = 1; left <= n; left++) {
			for (int right = 1; right <= n; right++) {
				dp[i][left][right] += (((dp[i - 1][left - 1][right]%mod) + (dp[i - 1][left][right - 1]%mod)%mod) + ((dp[i - 1][left][right] * (i - 2))%mod)%mod);
			}
		}
	}
	cout << dp[n][l][r] % mod << endl;
	return 1;
}