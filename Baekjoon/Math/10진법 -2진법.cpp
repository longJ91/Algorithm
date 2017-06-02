// 문제 : https://www.acmicpc.net/problem/2089
// 기존 진법 변환가 유사. 단, 나머지가 음수가 나오지 않게 유의하기
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main() {
	int N, temp;
	string result = "";
	cin >> N;
	if (N == 0) result = "0";
	while (N != 0) {
		if (N % 2 == 0) {
			N /= -2;
			result += "0";
		}
		else {
			if (N > 0) N /= -2;
			else N = (-N + 1) / 2;
			result += "1";
		}
	}
	reverse(result.begin(),result.end());
	cout << result;

	return 0;
}