// https://www.acmicpc.net/problem/10816
// Using Multiset (dc) - 또한 이 문제 처럼 출력 자체가 많은 경우 cin 과 cout 를 사용하면 성능이 느려져 시간초과가 발생 할 수 있다. 이럴 경우에는 scanf 와 prinf를 사용한다.
#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;
int main() {
	int N, M, temp;
	scanf("%d", &N);
	multiset<int> n;
	while (N--) {
		scanf("%d", &temp);
		n.insert(temp);
	}
	scanf("%d", &M);
	while (M--) {
		scanf("%d", &temp);
		printf("%d ", n.count(temp));
	}
	return 0;
}
/*
내가 봤을때 문제가 좀 쓰레기인거 같음.
아무튼 아래와 같이 했을 경우 모든 N, M 숫자가 같은 케이스에서 시간초과가 발생하지 않는다.
#include <cstdio>
using namespace std;
int cnt[20000001];
int main()
{
int N;
scanf("%d",&N);
while(N--)
{
int temp;
scanf("%d",&temp);
cnt[temp+10000000]++;
}
int M;
scanf("%d",&M);
while(M--)
{
int temp;
scanf("%d",&temp);
printf("%d ",cnt[temp+10000000]);
}

return 0;
}
*/