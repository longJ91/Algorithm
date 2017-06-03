// 문제 : https://www.acmicpc.net/problem/1978
// N이 소수라면, N/2보다 작거나 같은 자연수로 나누어 떨어지지 않는다.
// N이 소수라면, 루트N보다 작거나 같은 자연수로 나누어 떨어지지 않는다.
#include <iostream>
using namespace std;
int main() {
	int N,temp,result=0,flag;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		flag = 1;
		if (temp < 2) flag = -1;
		for (int j = 2; j*j <= temp; j++) {
			if (temp % j == 0) {
				flag = -1;
				break;
			}
		}
		if (flag == 1) result++;
	}
	cout << result;
	return 0;
}