// 문제 : https://www.acmicpc.net/problem/2745
// 유니코드를 활용
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main() {
	string N;
	char temp;
	int B, L, R=0;
	cin >> N >> B;
	L = N.size();
	for (int i = 1; i <= L; i++) {
		temp = N.at(i - 1);
		if (temp >= 65 && temp <= 91) {
			R += (int)((temp - 'A') + 10)*(int)pow(B, (double)(L-i-0));
		}
		else {
			R += (int)(temp - '0')*(int)pow(B, (double)(L-i-0));
		}
	}
	cout << R;
	return 0;
}