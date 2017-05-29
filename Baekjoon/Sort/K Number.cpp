// ���� : https://www.acmicpc.net/problem/11004
// ��� ��Ȱ� ���� �����ѵ� � �κп��� �ð��ʰ��� �߻� ��Ű���� �𸣰���
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int Set[5000000];
int main() {
	int N, K;
	cin >> N; cin >> K;
	for (int i = 0; i < N; i++) cin >> Set[i];
	nth_element(Set,Set+K,Set+N);
	cout << Set[K-1];
	return 1;
}
/*
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[5000000];
int main() {
int n,k;
scanf("%d %d",&n,&k);
k -= 1;
for (int i=0; i<n; i++) {
scanf("%d",&a[i]);
}
nth_element(a,a+k,a+n);
printf("%d\n",a[k]);
return 0;
}
*/