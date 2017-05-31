// 문제 : https://www.acmicpc.net/problem/1212
// 8진수 str의 가장 앞 부분의 0 값을 삭제 하는 예외 처리와 0 값 처리 중요
#include <iostream>
#include <string>
using namespace std;
int main() {
	string str,R;
	int len;
	cin >> str;
	len = str.size();
	for (int i = 0; i < len; i++) {
		int temp;
		R = "";
		temp = str.at(i) - '0';
		if (i == 0 && temp == 0) {
			cout << 0;
			break;
		}
		if (temp / 4 >= 1) {
			R += (temp / 4) + '0';
			temp %= 4;
		}
		else R += '0';
		if (temp / 2 >= 1) {
			R += (temp / 2) + '0';
			temp %= 2;
		}
		else R += '0';
		if (temp >= 1) {
			R += temp + '0';
			temp %= 2;
		}
		else R += '0';
		if (i == 0) {
			if (R.at(0) == '0') {
				if (R.at(1) == '0') R = "1";
				else {
					if (R.at(2) == '0') R = "10";
					else R = "11";
				}
			}
		}
		cout << R;
	}
	return 0;
}