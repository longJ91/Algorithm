// ���� : https://www.acmicpc.net/problem/10824
// ���� -> ���� (to_string(number)), ���� -> ���� (stoll(str)) 
// ���� : �־��� input value ���� �����ϱ�
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