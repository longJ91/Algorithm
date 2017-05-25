// 문제 : https://www.acmicpc.net/problem/2743
// for문 조건문에 문자열 배열을 활용해 문자열 길이를 구한다.
#include <iostream>
#include <string>

using namespace std;

int main() {

	string str;
	int count = 0;

	cin >> str;

	for (int i = 0; str[i]; i++) count++;

	cout << count;

	return 1;
}