// 문제 : https://www.acmicpc.net/problem/11004
// 모범 답안과 거의 유사한데 어떤 부분에서 시간초과를 발생 시키는지 모르겠음
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