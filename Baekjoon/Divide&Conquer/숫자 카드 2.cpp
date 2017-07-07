// https://www.acmicpc.net/problem/10816
// Using Multiset (dc) - ���� �� ���� ó�� ��� ��ü�� ���� ��� cin �� cout �� ����ϸ� ������ ������ �ð��ʰ��� �߻� �� �� �ִ�. �̷� ��쿡�� scanf �� prinf�� ����Ѵ�.
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
���� ������ ������ �� �������ΰ� ����.
�ƹ�ư �Ʒ��� ���� ���� ��� ��� N, M ���ڰ� ���� ���̽����� �ð��ʰ��� �߻����� �ʴ´�.
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