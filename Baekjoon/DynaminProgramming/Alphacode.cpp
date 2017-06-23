// ¹®Á¦ : https://www.acmicpc.net/problem/2011
// Botton Up
#include <iostream>
#include <string>
#include <stdlib.h>     /* atoi */
using namespace std;
#define limit 26
long long D[5001][2];
int main() {
	string num;
	int L, P;
	cin >> num;
	L = num.size();
	D[0][0]  = 1;
	D[0][1]  = 0;
	for (int i = 1; i <= L; i++) {
		if (num.at(i - 1) != '0') D[i][0] = (D[i - 1][0] + D[i - 1][1]) % 1000000;
		if (i == 1) continue;
		if (num.at(i - 2) == '0') continue;
		string temp;
		temp = num.substr(i-2,2);
		P = atoi(temp.c_str());
		if (P >= 10 && P < 27) D[i][1] = (D[i - 2][0] + D[i - 2][1]) % 1000000;
	}
	cout << (D[L][0] + D[L][1]) % 1000000 << endl;
	return 0;
}