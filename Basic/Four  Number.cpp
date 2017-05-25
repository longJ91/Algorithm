// 문제 : https://www.acmicpc.net/problem/10824
// 숫자 -> 문자 (to_string(number)), 문자 -> 숫자 (stoll(str)) 
// 주의 : 주어진 input value 범위 생각하기
#include <iostream>
#include <string>

using namespace std;

int main() {

	int one, two, three, four;
	string L, R;

	cin >> one;
	cin >> two;
	cin >> three;
	cin >> four;

	L = to_string(one) + to_string(two);
	R = to_string(three) + to_string(four);

	long long l = stoll(L);
	long long r = stoll(R);

	cout << l + r;

	return 1;
}