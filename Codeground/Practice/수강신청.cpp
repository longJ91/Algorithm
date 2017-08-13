/*
모든 경우의 수 체크
단, 최대 학점이 중복되는 경우를 사전에 검사해 계산을 줄인다.
-다른 풀이 참고함
*/
#include<stdio.h>
#include<iostream>
#include<vector>
#define Max(a,b) (a > b ? a : b)
using namespace std;

int main()
{
	int t, test = 1;
	cin >> t;
	while (test <= t)
	{
		int n, m;
		bool used[100001] = { true, };
		vector <int> g;
		int ans = 0, num, sum;
		cin >> n >> m;
		g.push_back(0);
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			for (int j = 0; j < g.size(); j++)
			{
				sum = g[j] + num;
				if (sum <= m && !used[sum]) {
					used[sum] = true;
					g.push_back(sum);
					ans = Max(ans, sum);
				}
			}
		}
		printf("Case #%d\n%d\n", test++, ans);
	}
}