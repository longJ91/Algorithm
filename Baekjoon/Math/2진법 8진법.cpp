// ���� : https://www.acmicpc.net/problem/1373
// 2���� N ���� 3�ڸ��� �߶� 8������ ��ȯ
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() {
	string two,R = "";
	int L, tempL;
	cin >> two;
	L = two.size();
	tempL = L % 3;
	if (tempL == 1) R += (1 * (int)(two.at(0) - '0')) + '0';
	if (tempL == 2) R += ((1 * (int)(two.at(1) - '0')) + (2 * (int)(two.at(0) - '0'))) + '0';
	for (int i = tempL; i < L; i += 3) R += ((1 * (int)(two.at(i+2) - '0')) + (2 * (int)(two.at(i+1) - '0')) + (4 * (int)(two.at(i) - '0'))) + '0';
	cout << R << endl;
	return 0;
}